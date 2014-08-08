/* Autogenerated with kurento-module-creator */

#include <gst/gst.h>
#include "MediaPipeline.hpp"
#include "MediaPipelineImpl.hpp"
#include <OpenCVFilterImplFactory.hpp>
#include "OpenCVFilterImpl.hpp"
#include <jsonrpc/JsonSerializer.hpp>
#include <KurentoException.hpp>
#include <gst/gst.h>

#define GST_CAT_DEFAULT kurento_open_cvfilter_impl
GST_DEBUG_CATEGORY_STATIC (GST_CAT_DEFAULT);
#define GST_DEFAULT_NAME "KurentoOpenCVFilterImpl"

namespace kurento
{

OpenCVFilterImpl::OpenCVFilterImpl (const boost::property_tree::ptree &conf,
                                    std::shared_ptr<MediaPipeline>
                                    mediaPipeline) : FilterImpl (conf, std::dynamic_pointer_cast<MediaPipelineImpl>
                                          (mediaPipeline) )
{
  g_object_set (element, "filter-factory", "opencvfilter", NULL);

  g_object_get (G_OBJECT (element), "filter", &opencvfilter, NULL);

  if (opencvfilter == NULL) {
    throw KurentoException (MEDIA_OBJECT_NOT_AVAILABLE,
                            "Media Object not available");
  }

  g_object_set (opencvfilter, "target-object",
                static_cast<kurento::OpenCVProcess *> (this), NULL);

  g_object_unref (opencvfilter);
}

OpenCVFilterImpl::StaticConstructor OpenCVFilterImpl::staticConstructor;

OpenCVFilterImpl::StaticConstructor::StaticConstructor()
{
  GST_DEBUG_CATEGORY_INIT (GST_CAT_DEFAULT, GST_DEFAULT_NAME, 0,
                           GST_DEFAULT_NAME);
}

} /* kurento */
