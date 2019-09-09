#include "node_printer.hpp"

#include <node_buffer.h>

void initNode(v8::Local<v8::Object> exports) {
// only for node
    Nan::SetMethod(exports, "getPrinters", getPrinters);
    Nan::SetMethod(exports, "getDefaultPrinterName", getDefaultPrinterName);
    Nan::SetMethod(exports, "getPrinter", getPrinter);
    Nan::SetMethod(exports, "getPrinterDriverOptions", getPrinterDriverOptions);
    Nan::SetMethod(exports, "getJob", getJob);
    Nan::SetMethod(exports, "setJob", setJob);
    Nan::SetMethod(exports, "printDirect", PrintDirect);
    Nan::SetMethod(exports, "printFile", PrintFile);
    Nan::SetMethod(exports, "getSupportedPrintFormats", getSupportedPrintFormats);
    Nan::SetMethod(exports, "getSupportedJobCommands", getSupportedJobCommands);
}

NODE_MODULE(node_printer, initNode);

// Helpers

bool getStringOrBufferFromV8Value(v8::Local<v8::Value> iV8Value, std::string &oData)
{
    if(iV8Value->IsString())
    {
        Nan::Utf8String data_str_v8(iV8Value->ToString(Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>()));
        oData.assign(*data_str_v8, data_str_v8.length());
        return true;
    }
    if(iV8Value->IsObject() && node::Buffer::HasInstance(iV8Value))
    {
        oData.assign(node::Buffer::Data(iV8Value), node::Buffer::Length(iV8Value));
        return true;
    }
    return false;
}
