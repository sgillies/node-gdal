#ifndef __NODE_GDAL_DATASET_H__
#define __NODE_GDAL_DATASET_H__

// v8
#include <v8.h>

// node
#include <node.h>
#include <node_object_wrap.h>

// gdal
#include <gdal_priv.h>

using namespace v8;
using namespace node;

class Dataset: public node::ObjectWrap {
  public:
    static Persistent<FunctionTemplate> constructor;
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments &args);
    static Handle<Value> New(GDALDataset *ds);
    static Handle<Value> toString(const Arguments &args);
    static Handle<Value> getRasterXSize(const Arguments &args);
    static Handle<Value> getRasterYSize(const Arguments &args);
    static Handle<Value> getRasterCount(const Arguments &args);
    static Handle<Value> getRasterBand(const Arguments &args);
    static Handle<Value> flushCache(const Arguments &args);
    static Handle<Value> getProjectionRef(const Arguments &args);
    static Handle<Value> setProjection(const Arguments &args);
    static Handle<Value> getGeoTransform(const Arguments &args);
    static Handle<Value> setGeoTransform(const Arguments &args);
    static Handle<Value> addBand(const Arguments &args);
    static Handle<Value> getDriver(const Arguments &args);
    static Handle<Value> getFileList(const Arguments &args);
    static Handle<Value> createMaskBand(const Arguments &args);
    static Handle<Value> getGCPCount(const Arguments &args);
    static Handle<Value> getGCPProjection(const Arguments &args);
    static Handle<Value> getGCPs(const Arguments &args);
    static Handle<Value> setGCPs(const Arguments &args);
    static Handle<Value> getMetadata(const Arguments &args);
    static Handle<Value> close(const Arguments &args);

    Dataset();
    Dataset(GDALDataset *ds);
    inline void nullify() { this_ = NULL; }
    inline GDALDataset *get() { return this_; }

  private:
    ~Dataset();
    GDALDataset *this_;
};

#endif
