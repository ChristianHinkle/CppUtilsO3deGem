
#pragma once

#include <CppUtilsO3deGem/CppUtilsO3deGemTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace CppUtilsO3deGem
{
    class CppUtilsO3deGemRequests
    {
    public:
        AZ_RTTI(CppUtilsO3deGemRequests, CppUtilsO3deGemRequestsTypeId);
        virtual ~CppUtilsO3deGemRequests() = default;
        // Put your public methods here
    };

    class CppUtilsO3deGemBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using CppUtilsO3deGemRequestBus = AZ::EBus<CppUtilsO3deGemRequests, CppUtilsO3deGemBusTraits>;
    using CppUtilsO3deGemInterface = AZ::Interface<CppUtilsO3deGemRequests>;

} // namespace CppUtilsO3deGem
