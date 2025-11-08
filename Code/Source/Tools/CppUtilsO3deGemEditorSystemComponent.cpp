
#include <AzCore/Serialization/SerializeContext.h>
#include "CppUtilsO3deGemEditorSystemComponent.h"

#include <CppUtilsO3deGem/CppUtilsO3deGemTypeIds.h>

namespace CppUtilsO3deGem
{
    AZ_COMPONENT_IMPL(CppUtilsO3deGemEditorSystemComponent, "CppUtilsO3deGemEditorSystemComponent",
        CppUtilsO3deGemEditorSystemComponentTypeId, BaseSystemComponent);

    void CppUtilsO3deGemEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<CppUtilsO3deGemEditorSystemComponent, CppUtilsO3deGemSystemComponent>()
                ->Version(0);
        }
    }

    CppUtilsO3deGemEditorSystemComponent::CppUtilsO3deGemEditorSystemComponent() = default;

    CppUtilsO3deGemEditorSystemComponent::~CppUtilsO3deGemEditorSystemComponent() = default;

    void CppUtilsO3deGemEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("CppUtilsO3deGemEditorService"));
    }

    void CppUtilsO3deGemEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("CppUtilsO3deGemEditorService"));
    }

    void CppUtilsO3deGemEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void CppUtilsO3deGemEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    void CppUtilsO3deGemEditorSystemComponent::Activate()
    {
        CppUtilsO3deGemSystemComponent::Activate();
        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void CppUtilsO3deGemEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();
        CppUtilsO3deGemSystemComponent::Deactivate();
    }

} // namespace CppUtilsO3deGem
