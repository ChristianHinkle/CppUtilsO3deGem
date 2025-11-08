
#pragma once

namespace CppUtilsO3deGem
{
    // System Component TypeIds
    inline constexpr const char* CppUtilsO3deGemSystemComponentTypeId = "{59FFD03E-E1A2-406C-9827-C4C1CCD1874B}";
    inline constexpr const char* CppUtilsO3deGemEditorSystemComponentTypeId = "{60F202EC-5E91-4915-BCEF-0150F8550046}";

    // Module derived classes TypeIds
    inline constexpr const char* CppUtilsO3deGemModuleInterfaceTypeId = "{95B10834-C11C-4DA9-9481-CABB054B149B}";
    inline constexpr const char* CppUtilsO3deGemModuleTypeId = "{09E78EC4-0772-4BD6-A972-DAF33AA10344}";
    // The Editor Module by default is mutually exclusive with the Client Module
    // so they use the Same TypeId
    inline constexpr const char* CppUtilsO3deGemEditorModuleTypeId = CppUtilsO3deGemModuleTypeId;

    // Interface TypeIds
    inline constexpr const char* CppUtilsO3deGemRequestsTypeId = "{CC60D640-FCE6-4B4C-BC71-FA2A12FBE373}";
} // namespace CppUtilsO3deGem
