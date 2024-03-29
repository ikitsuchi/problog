add_requires("nlohmann_json")
add_requires("cvc5")
target("problog")
    set_kind("binary")
    add_headerfiles("./include/*.hpp")
    add_files("*.cpp")
    add_packages("nlohmann_json")
    set_languages("c++20")
    set_optimize("fastest")
    add_cxxflags("-O3")
    add_links("cvc5")
