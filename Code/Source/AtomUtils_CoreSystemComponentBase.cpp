
#include <Source/AtomUtils_CoreSystemComponentBase.h>

#include <AtomUtils_CoreTypeIds.h>
#include <AzCore/Serialization/SerializeContext.h>

namespace AtomUtils
{
    AZ_COMPONENT_IMPL(AtomUtils_CoreSystemComponentBase, "AtomUtils_CoreSystemComponentBase",
        AtomUtils_CoreSystemComponentBaseTypeId);

    void AtomUtils_CoreSystemComponentBase::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<AtomUtils_CoreSystemComponentBase, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void AtomUtils_CoreSystemComponentBase::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("AtomUtils_CoreBaseService"));
    }

    void AtomUtils_CoreSystemComponentBase::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("AtomUtils_CoreBaseService"));
    }

    void AtomUtils_CoreSystemComponentBase::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void AtomUtils_CoreSystemComponentBase::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        // @Christian: TODO: [todo][techdebt][workaround][engine] Fix this properly with an engine pull request to allow multiplayer components to exist in
        // multiple gems without worrying about the order that they are registered in. We add this dependency on the multiplayer system component to make sure
        // it activates (and registers its multiplayer components) before we activate (and register our multiplayer components). In editor, it seems that
        // the AtomUtils_Core system component activates before the Multiplayer system component, but the opposite happens in non-editor. This would cause the
        // net component IDs to get mismatched between the different targets, and then testing dedicated server in editor would break.
        dependent.push_back(AZ_CRC_CE("MultiplayerService"));
    }

    AtomUtils_CoreSystemComponentBase::AtomUtils_CoreSystemComponentBase()
    {
        if (AtomUtils_CoreInterface::Get() == nullptr)
        {
            AtomUtils_CoreInterface::Register(this);
        }
    }

    AtomUtils_CoreSystemComponentBase::~AtomUtils_CoreSystemComponentBase()
    {
        if (AtomUtils_CoreInterface::Get() == this)
        {
            AtomUtils_CoreInterface::Unregister(this);
        }
    }

    void AtomUtils_CoreSystemComponentBase::Init()
    {
    }

    void AtomUtils_CoreSystemComponentBase::Activate()
    {
        AtomUtils_CoreRequestBus::Handler::BusConnect();
        AZ::TickBus::Handler::BusConnect();
    }

    void AtomUtils_CoreSystemComponentBase::Deactivate()
    {
        AZ::TickBus::Handler::BusDisconnect();
        AtomUtils_CoreRequestBus::Handler::BusDisconnect();
    }

    void AtomUtils_CoreSystemComponentBase::OnTick([[maybe_unused]] float deltaTime, [[maybe_unused]] AZ::ScriptTimePoint time)
    {
    }
}
