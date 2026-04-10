
#include <Source/Tools/AtomUtils_CoreEditorSystemComponent.h>

#include <AtomUtils_CoreTypeIds.h>
#include <AzCore/Serialization/SerializeContext.h>

namespace AtomUtils
{
    AZ_COMPONENT_IMPL(AtomUtils_CoreEditorSystemComponent, "AtomUtils_CoreEditorSystemComponent",
        AtomUtils_CoreEditorSystemComponentTypeId, BaseSystemComponent);

    void AtomUtils_CoreEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<AtomUtils_CoreEditorSystemComponent, BaseSystemComponent>()
                ->Version(0)
                ;
        }
    }

    void AtomUtils_CoreEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("AtomUtils_CoreEditorService"));
    }

    void AtomUtils_CoreEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("AtomUtils_CoreEditorService"));
    }

    void AtomUtils_CoreEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void AtomUtils_CoreEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    AtomUtils_CoreEditorSystemComponent::AtomUtils_CoreEditorSystemComponent() = default;
    AtomUtils_CoreEditorSystemComponent::~AtomUtils_CoreEditorSystemComponent() = default;

    void AtomUtils_CoreEditorSystemComponent::Activate()
    {
        BaseSystemComponent::Activate();

        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void AtomUtils_CoreEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();

        BaseSystemComponent::Deactivate();
    }
}
