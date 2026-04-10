
#pragma once

#include <AzCore/Component/Component.h>
#include <AtomUtils_CoreBus.h>
#include <AzCore/Component/TickBus.h>
#include <AtomUtils_CoreConfiguration.h>

namespace AtomUtils
{
    class ATOMUTILS_CORE_API AtomUtils_CoreSystemComponentBase
        : public AZ::Component
        , protected AtomUtils_CoreRequestBus::Handler
        , public AZ::TickBus::Handler
    {
    public:
        AZ_COMPONENT_DECL_API(ATOMUTILS_CORE_API, AtomUtils_CoreSystemComponentBase);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        AtomUtils_CoreSystemComponentBase();
        ~AtomUtils_CoreSystemComponentBase();

    protected:
        //! AtomUtils_CoreRequestBus::Handler overrides.
        //! @{
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        //! @}

        //! AZ::TickBus::Handler overrides.
        //! @{
        void OnTick(float deltaTime, AZ::ScriptTimePoint time) override;
        //! @}
    };
}
