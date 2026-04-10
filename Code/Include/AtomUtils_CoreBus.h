
#pragma once

#include <AtomUtils_CoreTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace AtomUtils
{
    class AtomUtils_CoreRequests
    {
    public:
        AZ_RTTI(AtomUtils_CoreRequests, AtomUtils_CoreRequestsTypeId);
        virtual ~AtomUtils_CoreRequests() = default;
        // Put your public methods here
    };

    class AtomUtils_CoreBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using AtomUtils_CoreRequestBus = AZ::EBus<AtomUtils_CoreRequests, AtomUtils_CoreBusTraits>;
    using AtomUtils_CoreInterface = AZ::Interface<AtomUtils_CoreRequests>;

}
