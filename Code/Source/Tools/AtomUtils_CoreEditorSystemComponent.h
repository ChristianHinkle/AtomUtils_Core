
#pragma once

#include <Source/AtomUtils_CoreSystemComponentBase.h>
#include <AzToolsFramework/API/ToolsApplicationAPI.h>

namespace AtomUtils
{
    class AtomUtils_CoreEditorSystemComponent
        : public AtomUtils_CoreSystemComponentBase
        , protected AzToolsFramework::EditorEvents::Bus::Handler
    {
        using BaseSystemComponent = AtomUtils_CoreSystemComponentBase;
    public:
        AZ_COMPONENT_DECL(AtomUtils_CoreEditorSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        AtomUtils_CoreEditorSystemComponent();
        ~AtomUtils_CoreEditorSystemComponent();

    protected:

        void Activate() override;
        void Deactivate() override;
    };
}
