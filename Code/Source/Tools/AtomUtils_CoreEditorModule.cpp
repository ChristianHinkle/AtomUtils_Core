
#include <Source/AtomUtils_CoreModuleInterface.h>
#include <AtomUtils_CoreTypeIds.h>
#include <Source/Tools/AtomUtils_CoreEditorSystemComponent.h>

namespace AtomUtils
{
    class AtomUtils_CoreEditorModule : public AtomUtils_CoreModuleInterface
    {
    public:
        AZ_RTTI(AtomUtils_CoreEditorModule, AtomUtils_CoreEditorModuleTypeId, AtomUtils_CoreModuleInterface);
        AZ_CLASS_ALLOCATOR(AtomUtils_CoreEditorModule, AZ::SystemAllocator);

        AtomUtils_CoreEditorModule()
        {
            // Append editor-only items.
            m_descriptors.insert(m_descriptors.end(), {
                AtomUtils_CoreEditorSystemComponent::CreateDescriptor(),
                }
            );
        }

        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            AZ::ComponentTypeList list = AtomUtils_CoreModuleInterface::GetRequiredSystemComponents();

            // Append editor-only items.
            list.insert(list.end(), {
                azrtti_typeid<AtomUtils_CoreEditorSystemComponent>(),
                }
            );

            return list;
        }
    };
}

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME, _Editor), AtomUtils::AtomUtils_CoreEditorModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_AtomUtils_Core_Editor, AtomUtils::AtomUtils_CoreEditorModule)
#endif
