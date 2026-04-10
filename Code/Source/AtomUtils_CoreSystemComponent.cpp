
#include <Source/AtomUtils_CoreSystemComponent.h>

#include <AtomUtils_CoreTypeIds.h>
#include <AzCore/Serialization/SerializeContext.h>

namespace AtomUtils
{
    AZ_COMPONENT_IMPL(AtomUtils_CoreSystemComponent, "AtomUtils_CoreSystemComponent",
        AtomUtils_CoreSystemComponentTypeId, BaseSystemComponent);

    void AtomUtils_CoreSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<AtomUtils_CoreSystemComponent, BaseSystemComponent>()
                ->Version(0)
                ;
        }
    }

    void AtomUtils_CoreSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("AtomUtils_CoreService"));
    }

    void AtomUtils_CoreSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("AtomUtils_CoreService"));
    }

    void AtomUtils_CoreSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void AtomUtils_CoreSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    AtomUtils_CoreSystemComponent::AtomUtils_CoreSystemComponent() = default;
    AtomUtils_CoreSystemComponent::~AtomUtils_CoreSystemComponent() = default;

    void AtomUtils_CoreSystemComponent::Activate()
    {
        BaseSystemComponent::Activate();
    }

    void AtomUtils_CoreSystemComponent::Deactivate()
    {
        BaseSystemComponent::Deactivate();
    }
}
