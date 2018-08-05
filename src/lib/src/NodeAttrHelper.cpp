//
// Created by daquexian on 8/3/18.
//

#include "NodeAttrHelper.h"

#include <string>
#include <vector>

using std::string; using std::vector;

NodeAttrHelper::NodeAttrHelper(onnx::NodeProto proto) : node_(proto){

}

float NodeAttrHelper::get(const std::string &key, float def_val) {
    for (int i = 0; i < node_.attribute_size(); i++) {
        const onnx::AttributeProto& attr = node_.attribute(i);
        if (attr.name() == key) {
            return attr.f();
        }
    }

    return def_val;
}

int NodeAttrHelper::get(const std::string &key, int def_val) {
    for (int i = 0; i < node_.attribute_size(); i++) {
        const onnx::AttributeProto& attr = node_.attribute(i);
        if (attr.name() == key) {
            return static_cast<int>(attr.i());
        }
    }

    return def_val;
}

string NodeAttrHelper::get(const std::string &key, string def_val) {
    for (int i = 0; i < node_.attribute_size(); i++) {
        const onnx::AttributeProto& attr = node_.attribute(i);
        if (attr.name() == key) {
            return attr.s();
        }
    }

    return def_val;
}

vector<int> NodeAttrHelper::get(const std::string &key, vector<int> def_val) {
    std::vector<int> v;

    for (int i = 0; i < node_.attribute_size(); i++) {
        const onnx::AttributeProto& attr = node_.attribute(i);
        if (attr.name() == key) {
            v.resize(static_cast<unsigned long>(attr.ints_size()));
            for (int j = 0; j < attr.ints_size(); j++) {
                v.push_back(static_cast<int>(attr.ints(j)));
            }

            break;
        }
    }

    return def_val;
}

vector<float> NodeAttrHelper::get(const std::string &key, vector<float> def_val) {
    std::vector<float> v;

    for (int i = 0; i < node_.attribute_size(); i++) {
        const onnx::AttributeProto &attr = node_.attribute(i);
        if (attr.name() == key) {
            v.resize(attr.floats_size());
            for (int j = 0; j < attr.floats_size(); j++) {
                v.push_back(attr.floats(j));
            }

            break;
        }
    }

    return def_val;
}

bool NodeAttrHelper::has_attr(const std::string &key) {
    for (int i = 0; i < node_.attribute_size(); i++) {
        const onnx::AttributeProto &attr = node_.attribute(i);
        if (attr.name() == key) {
            return true;
        }
    }

    return false;
}