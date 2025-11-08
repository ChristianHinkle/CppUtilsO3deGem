
#include <CppUtilsO3deGem/CppUtilsO3deGemTypeIds.h>
#include <CppUtilsO3deGemModuleInterface.h>
#include "CppUtilsO3deGemSystemComponent.h"

namespace CppUtilsO3deGem
{
    class CppUtilsO3deGemModule
        : public CppUtilsO3deGemModuleInterface
    {
    public:
        AZ_RTTI(CppUtilsO3deGemModule, CppUtilsO3deGemModuleTypeId, CppUtilsO3deGemModuleInterface);
        AZ_CLASS_ALLOCATOR(CppUtilsO3deGemModule, AZ::SystemAllocator);
    };
}// namespace CppUtilsO3deGem

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), CppUtilsO3deGem::CppUtilsO3deGemModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_CppUtilsO3deGem, CppUtilsO3deGem::CppUtilsO3deGemModule)
#endif
