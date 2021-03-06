#ifndef COVARIANCE_PROPERTY_H
#define COVARIANCE_PROPERTY_H

#include <QColor>

#include <OgreColourValue.h>

#include <rviz/properties/bool_property.h>

namespace rviz
{
class Property;
class ColorProperty;
class FloatProperty;
}

namespace rviz_plugin_covariance
{

/** @brief Property specialized to provide getter for booleans. */
class CovarianceProperty: public rviz::BoolProperty
{
Q_OBJECT
public:
  CovarianceProperty( const QString& name = "Covariance",
                bool default_value = false,
                const QString& description = QString(),
                rviz::Property* parent = 0,
                const char *changed_slot = 0,
                QObject* receiver = 0 );

  virtual ~CovarianceProperty();

  Ogre::ColourValue getPositionOgreColor();
  QColor getPositionColor() const;
  float getPositionAlpha();
  float getPositionScale();

  Ogre::ColourValue getOrientationOgreColor();
  QColor getOrientationColor() const;
  float getOrientationAlpha();
  float getOrientationScale();

Q_SIGNALS:
  bool childrenChanged();

private:
  rviz::ColorProperty* position_color_property_;
  rviz::FloatProperty* position_alpha_property_;
  rviz::FloatProperty* position_scale_property_;
  rviz::ColorProperty* orientation_color_property_;
  rviz::FloatProperty* orientation_alpha_property_;
  rviz::FloatProperty* orientation_scale_property_;
};

} // end namespace rviz_plugin_covariance

#endif // COVARIANCE_PROPERTY_H
