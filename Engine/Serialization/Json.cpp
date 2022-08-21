#include "Json.h"
#include "istreamwrapper.h"
#include "Core/Logger.h"
#include "Math/Vector2.h"
#include "Math/Color.h"
#include <fstream>


namespace neum {
    namespace json 
    {
        bool Load(const std::string& filename, rapidjson::Document& document)
        {
            // Create std::ifstream object
            // Check if it is open, if not use LOG to print error and return false
            std::ifstream stream(filename);

            if (stream.is_open() == false)
            {
                LOG("error opening file %s.", filename.c_str());
                return false;
            }

            rapidjson::IStreamWrapper istream(stream);
            document.ParseStream(istream);
            if (document.IsObject() == false)
            {
                LOG("json file cannot be read %s.", filename.c_str());
                return false;
            }

            return true;
        }

        bool Get(rapidjson::Value& value, const std::string& name, int& data)
        {
            // Check if 'name' member exists and is of type

            if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsInt() == false)
            {
                LOG("error reading json data %s", name.c_str());
                return false;
            }
            // Set data
            data = value[name.c_str()].GetInt();
            return true;

        }

        bool Get(const rapidjson::Value& value, const std::string& name, float& data)
        {
            // Check if 'name' member exusts and is of type
            if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsFloat() == false)
            {
                LOG("Error reading json data %s.", name.c_str());
                return false;
            }
            // Set data
            data = value[name.c_str()].GetFloat();
            return true;
        }

        bool Get(const rapidjson::Value& value, const std::string& name, bool& data)
        {
            if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsBool() == false)
            { 
                LOG("Error reading json data %s.", name.c_str());
                return false;
            }
            data = value[name.c_str()].GetBool();
            return true;
        }

        bool Get(const rapidjson::Value& value, const std::string& name, std::string& data)
        {
            if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsString() == false)
            {
                LOG("Error reading json data %s.", name.c_str());
                return false;
            }
            data = value[name.c_str()].GetString();
            return true;
        }

        bool Get(const rapidjson::Value& value, const std::string& name, Vector2& data)
        {
            if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsArray() == false)
            {
                LOG("Error reading json data %s.", name.c_str());
                return false;
            }

            auto& array = value[name.c_str()];
            for (rapidjson::SizeType i = 0; i < array.Size(); i++)
            {
                if (!array[i].IsFloat()) 
                {
                    LOG("Error reading json data (not a float) %s.", name.c_str());
                    return false;
                }
            data[i] = array[i].GetFloat();
            }
            return true;
        }

        bool Get(const rapidjson::Value& value, const std::string& name, Color& data)
        {
            if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsArray() == false)
            {
                LOG("Error reading json data %s.", name.c_str());
                return false;
            }

            auto& array = value[name.c_str()];
            for (rapidjson::SizeType i = 0; i < array.Size(); i++)
            {
                if (!array[i].IsInt())
                {
                    LOG("Error reading json data (not an int) %s.", name.c_str());
                    return false;
                }
                data[i] = array[i].GetInt();
            }
            return true;
        }
    }

}
