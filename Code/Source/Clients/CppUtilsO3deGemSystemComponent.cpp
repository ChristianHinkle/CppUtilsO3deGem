
#include "CppUtilsO3deGemSystemComponent.h"

#include <CppUtilsO3deGem/CppUtilsO3deGemTypeIds.h>

#include <AzCore/Serialization/SerializeContext.h>

namespace CppUtilsO3deGem
{
    AZ_COMPONENT_IMPL(CppUtilsO3deGemSystemComponent, "CppUtilsO3deGemSystemComponent",
        CppUtilsO3deGemSystemComponentTypeId);

    void CppUtilsO3deGemSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<CppUtilsO3deGemSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void CppUtilsO3deGemSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("CppUtilsO3deGemService"));
    }

    void CppUtilsO3deGemSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("CppUtilsO3deGemService"));
    }

    void CppUtilsO3deGemSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void CppUtilsO3deGemSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    CppUtilsO3deGemSystemComponent::CppUtilsO3deGemSystemComponent()
    {
        if (CppUtilsO3deGemInterface::Get() == nullptr)
        {
            CppUtilsO3deGemInterface::Register(this);
        }
    }

    CppUtilsO3deGemSystemComponent::~CppUtilsO3deGemSystemComponent()
    {
        if (CppUtilsO3deGemInterface::Get() == this)
        {
            CppUtilsO3deGemInterface::Unregister(this);
        }
    }

    void CppUtilsO3deGemSystemComponent::Init()
    {
    }

    void CppUtilsO3deGemSystemComponent::Activate()
    {
        CppUtilsO3deGemRequestBus::Handler::BusConnect();
        AZ::TickBus::Handler::BusConnect();
    }

    void CppUtilsO3deGemSystemComponent::Deactivate()
    {
        AZ::TickBus::Handler::BusDisconnect();
        CppUtilsO3deGemRequestBus::Handler::BusDisconnect();
    }

    void CppUtilsO3deGemSystemComponent::OnTick([[maybe_unused]] float deltaTime, [[maybe_unused]] AZ::ScriptTimePoint time)
    {
    }

} // namespace CppUtilsO3deGem
