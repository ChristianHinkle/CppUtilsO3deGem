
o3de_gem_setup("CppUtils")

string(TOLOWER ${gem_name} gem_name_lowercase)
string(TOUPPER ${gem_name} gem_name_uppercase)

add_subdirectory(3rdParty)

ly_add_external_target_path(${CMAKE_CURRENT_SOURCE_DIR}/3rdParty)
