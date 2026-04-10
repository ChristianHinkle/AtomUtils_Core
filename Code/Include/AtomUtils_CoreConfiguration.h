
#pragma once

#include <AzCore/PlatformDef.h>

#if defined(AZ_MONOLITHIC_BUILD)
#   define ATOMUTILS_CORE_API
#else
#   if defined(ATOMUTILS_CORE_EXPORTS)
#       define ATOMUTILS_CORE_API AZ_DLL_EXPORT
#   else
#       define ATOMUTILS_CORE_API AZ_DLL_IMPORT
#   endif
#endif
