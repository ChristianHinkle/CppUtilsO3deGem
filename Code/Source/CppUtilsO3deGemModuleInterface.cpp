
#include "CppUtilsO3deGemModuleInterface.h"
#include <AzCore/Memory/Memory.h>

#include <CppUtilsO3deGem/CppUtilsO3deGemTypeIds.h>

#include <Clients/CppUtilsO3deGemSystemComponent.h>

namespace CppUtilsO3deGem
{
    AZ_TYPE_INFO_WITH_NAME_IMPL(CppUtilsO3deGemModuleInterface,
        "CppUtilsO3deGemModuleInterface", CppUtilsO3deGemModuleInterfaceTypeId);
    AZ_RTTI_NO_TYPE_INFO_IMPL(CppUtilsO3deGemModuleInterface, AZ::Module);
    AZ_CLASS_ALLOCATOR_IMPL(CppUtilsO3deGemModuleInterface, AZ::SystemAllocator);

    CppUtilsO3deGemModuleInterface::CppUtilsO3deGemModuleInterface()
    {
        // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
        // Add ALL components descriptors associated with this gem to m_descriptors.
        // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
        // This happens through the [MyComponent]::Reflect() function.
        m_descriptors.insert(m_descriptors.end(), {
            CppUtilsO3deGemSystemComponent::CreateDescriptor(),
            });
    }

    AZ::ComponentTypeList CppUtilsO3deGemModuleInterface::GetRequiredSystemComponents() const
    {
        return AZ::ComponentTypeList{
            azrtti_typeid<CppUtilsO3deGemSystemComponent>(),
        };
    }
} // namespace CppUtilsO3deGem
