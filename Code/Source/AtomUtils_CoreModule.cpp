
#include <Source/AtomUtils_CoreModuleInterface.h>
#include <AtomUtils_CoreTypeIds.h>
#include <Source/AtomUtils_CoreSystemComponent.h>

namespace AtomUtils
{
    class AtomUtils_CoreModule : public AtomUtils_CoreModuleInterface
    {
    public:
        AZ_RTTI(AtomUtils_CoreModule, AtomUtils_CoreModuleTypeId, AtomUtils_CoreModuleInterface);
        AZ_CLASS_ALLOCATOR(AtomUtils_CoreModule, AZ::SystemAllocator);

        AtomUtils_CoreModule()
        {
            // Append non-editor items.
            m_descriptors.insert(m_descriptors.end(), {
                AtomUtils_CoreSystemComponent::CreateDescriptor(),
                }
            );
        }

        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            AZ::ComponentTypeList list = AtomUtils_CoreModuleInterface::GetRequiredSystemComponents();

            // Append non-editor items.
            list.insert(list.end(), {
                azrtti_typeid<AtomUtils_CoreSystemComponent>(),
                }
            );

            return list;
        }
    };
}

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), AtomUtils::AtomUtils_CoreModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_AtomUtils_Core, AtomUtils::AtomUtils_CoreModule)
#endif
