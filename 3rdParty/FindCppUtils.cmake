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

unset(MY_GEM_NAME)
