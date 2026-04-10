
#pragma once

#include <AzCore/Module/Module.h>
#include <AzCore/Memory/Memory_fwd.h>
#include <AzCore/RTTI/RTTIMacros.h>
#include <AzCore/RTTI/TypeInfoSimple.h>
#include <AtomUtils_CoreConfiguration.h>

namespace AtomUtils
{
    class ATOMUTILS_CORE_API AtomUtils_CoreModuleInterface : public AZ::Module
    {
    public:
        AZ_TYPE_INFO_WITH_NAME_DECL_API(ATOMUTILS_CORE_API, AtomUtils_CoreModuleInterface);
        AZ_RTTI_NO_TYPE_INFO_DECL();
        AZ_CLASS_ALLOCATOR_DECL;

        AtomUtils_CoreModuleInterface();

        AZ::ComponentTypeList GetRequiredSystemComponents() const override;
    };
}
