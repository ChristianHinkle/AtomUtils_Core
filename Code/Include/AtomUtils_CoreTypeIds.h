
#pragma once

namespace AtomUtils
{
    // System Component TypeIds
    inline constexpr const char* AtomUtils_CoreSystemComponentBaseTypeId = "{2E70289F-C56D-42B8-BDDB-98BD3892658D}";
    inline constexpr const char* AtomUtils_CoreSystemComponentTypeId = "{2D80C33E-42F4-45F8-B57C-793886A8DA4F}";
    inline constexpr const char* AtomUtils_CoreEditorSystemComponentTypeId = "{BF3FC066-9CA0-46D5-9FF0-C84E0EA508A3}";

    // Module derived classes TypeIds
    inline constexpr const char* AtomUtils_CoreModuleInterfaceTypeId = "{C0734EA2-8F03-47CB-A091-587DABE2CB49}";
    inline constexpr const char* AtomUtils_CoreModuleTypeId = "{87FB729B-9E69-48DC-B080-42218BA5BDF7}";
    // The Editor Module by default is mutually exclusive with the Client Module
    // so they use the Same TypeId
    inline constexpr const char* AtomUtils_CoreEditorModuleTypeId = AtomUtils_CoreModuleTypeId;

    // Interface TypeIds
    inline constexpr const char* AtomUtils_CoreRequestsTypeId = "{99F91CA8-B44A-4675-9382-D0BB262ECA8E}";
}
