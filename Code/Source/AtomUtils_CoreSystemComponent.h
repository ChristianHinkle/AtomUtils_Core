
#pragma once

#include <Source/AtomUtils_CoreSystemComponentBase.h>

namespace AtomUtils
{
    class AtomUtils_CoreSystemComponent
        : public AtomUtils_CoreSystemComponentBase
    {
        using BaseSystemComponent = AtomUtils_CoreSystemComponentBase;
    public:
        AZ_COMPONENT_DECL(AtomUtils_CoreSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        AtomUtils_CoreSystemComponent();
        ~AtomUtils_CoreSystemComponent();

    protected:

        void Activate() override;
        void Deactivate() override;
    };
}
