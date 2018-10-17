//
// codoc (c) blacktriangles 2018
//

#include "codoc/config/document.hh"

#include <cassert>
#include <fstream>

namespace codoc::config
{

//
// constructor / destructor ###################################################
//

document::document()
    : m_root()
{
}

//
// ----------------------------------------------------------------------------
//

document::document(const std::string& config_path)
    : m_root()
{
    bool success = parse(config_path);
    assert(success);
}

//
// ----------------------------------------------------------------------------
//

document::document(std::istream& stream)
    : m_root()
{
    bool success = parse(stream);
    assert(success);
}

//
// public methods #############################################################
//

bool document::load(const std::string& config_path)
{
    std::ifstream stream(config_path, std::ios::in);
    return parse(stream);
}

//
// ----------------------------------------------------------------------------
//

bool document::parse(const std::string& data)
{
    std::stringstream stream(data, std::ios::in);
    return parse(stream);
}

//
// ----------------------------------------------------------------------------
//

bool document::parse(std::istream& stream)
{
    YAML::Node node = YAML::Load(stream);
    m_root = section(node);
    return true;
}

//
// ----------------------------------------------------------------------------
//

const section& document::get_root() const
{
    return m_root;
}


//
// ############################################################################
//

}
