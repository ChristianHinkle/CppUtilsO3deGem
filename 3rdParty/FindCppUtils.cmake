# Copyright (c) 2023-2025 Christian Hinkle, Brian Hinkle.

set(MY_GEM_NAME "CppUtils")

if(TARGET 3rdParty::${MY_GEM_NAME})
    return()
endif()

get_property(MY_GEM_ROOT GLOBAL PROPERTY "@GEMROOT:${MY_GEM_NAME}@")

ly_add_external_target(
    NAME CppUtils
    3RDPARTY_ROOT_DIRECTORY "${MY_GEM_ROOT}/3rdParty/CppUtils"
    VERSION
)

unset(MY_GEM_ROOT)

#
# @Christian: TODO: [todo][temporary[engine]][cmake] Use the `o3de_fixup_fetchcontent_targets` function on all the 3rdParty targets
# so that they each get aliases with the "3rdParty::" prefix and stuff. This function isn't available for us yet so we have to
# wait. It looks like this current engine version is on pretty a old version of the engine's "cmake" directory. The function
# we want to use was introduced by commit: https://github.com/o3de/o3de/commit/0e62fa1805f2654d9d376154d1504ce069751db5.
#
# For now, we'll just have the `ly_add_target` calls use the "CppUtils::" targets directly - without the "3rdParty::" prefix.
#

# @Christian: Here is an idea on conditionally linking statically vs dynamically based on whether we are builing the game monolithically or
# not. This isn't a full solution because we can't control how transient dependencies are being linked.

# Choose the linkable library type based on whether we will build monolithically or not.
if(LY_MONOLITHIC_GAME)
    set(LinkableLibraryName "Static")
else()
    set(LinkableLibraryName "Shared")
endif()

# List out all the target names that are linkable (e.g., have static and shared libraries).
set(LinkableLibraryTargetBaseNames
    CppUtils::Core
    CppUtils::Misc
)

# Generate the alias targets which are prefixed with "3rdParty::" as per the naming convention of O3DE's 3rdParty library usage.
foreach(TargetBaseName IN LISTS ${LinkableLibraryTargetBaseNames})

    get_target_property(TargetFullName ${TargetBaseName}::${LinkableLibraryName} ALIASED_TARGET)
    add_library(3rdParty::${TargetBaseName}.Linkable ALIAS ${TargetFullName})

endforeach()

unset(LinkableLibraryName)

# List out all the target names that have public API libraries (e.g., interface libraries).
set(ApiLibraryTargetBaseNames
    CppUtils::Concepts
)

# Assume that linkable library targets also have public API targets.
list(APPEND ApiLibraryTargetBaseNames LinkableLibraryTargetBaseNames)

unset(LinkableLibraryTargetBaseNames)

# Choose the API library name.
set(ApiLibraryName "Include")

# Generate the alias targets which are prefixed with "3rdParty::" as per the naming convention of O3DE's 3rdParty library usage.
foreach(TargetBaseName IN LISTS ${ApiLibraryTargetBaseNames})

    get_target_property(TargetFullName ${TargetBaseName}::${ApiLibraryName} ALIASED_TARGET)
    add_library(3rdParty::${TargetBaseName}.API ALIAS ${TargetFullName})

endforeach()

unset(ApiLibraryName)

unset(MY_GEM_NAME)
