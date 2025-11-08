
#include <CppUtilsO3deGem/CppUtilsO3deGemTypeIds.h>
#include <CppUtilsO3deGemModuleInterface.h>
#include "CppUtilsO3deGemEditorSystemComponent.h"

namespace CppUtilsO3deGem
{
    class CppUtilsO3deGemEditorModule
        : public CppUtilsO3deGemModuleInterface
    {
    public:
        AZ_RTTI(CppUtilsO3deGemEditorModule, CppUtilsO3deGemEditorModuleTypeId, CppUtilsO3deGemModuleInterface);
        AZ_CLASS_ALLOCATOR(CppUtilsO3deGemEditorModule, AZ::SystemAllocator);

        CppUtilsO3deGemEditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                CppUtilsO3deGemEditorSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<CppUtilsO3deGemEditorSystemComponent>(),
            };
        }
    };
}// namespace CppUtilsO3deGem

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME, _Editor), CppUtilsO3deGem::CppUtilsO3deGemEditorModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_CppUtilsO3deGem_Editor, CppUtilsO3deGem::CppUtilsO3deGemEditorModule)
#endif
