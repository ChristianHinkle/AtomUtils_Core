
#include <Source/AtomUtils_CoreModuleInterface.h>

#include <AzCore/Memory/Memory.h>

#include <AtomUtils_CoreTypeIds.h>

#include <Source/AtomUtils_CoreSystemComponent.h>

namespace AtomUtils
{
    AZ_TYPE_INFO_WITH_NAME_IMPL(AtomUtils_CoreModuleInterface, "AtomUtils_CoreModuleInterface", AtomUtils_CoreModuleInterfaceTypeId);
    AZ_RTTI_NO_TYPE_INFO_IMPL(AtomUtils_CoreModuleInterface, AZ::Module);
    AZ_CLASS_ALLOCATOR_IMPL(AtomUtils_CoreModuleInterface, AZ::SystemAllocator);

    AtomUtils_CoreModuleInterface::AtomUtils_CoreModuleInterface()
    {
        // Append all items used by both editor and non-editor targets.
        m_descriptors.insert(m_descriptors.end(), {
            AtomUtils_CoreSystemComponent::CreateDescriptor(),
            }
        );
    }

    AZ::ComponentTypeList AtomUtils_CoreModuleInterface::GetRequiredSystemComponents() const
    {
        // Append all items used by both editor and non-editor targets.
        return AZ::ComponentTypeList{
        };
    }
}
