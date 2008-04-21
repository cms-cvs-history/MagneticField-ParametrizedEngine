#ifndef ParametrizedEngine_OAE85lParametrizedMagneticField_h
#define ParametrizedEngine_OAE85lParametrizedMagneticField_h

/** \class OAE85lParametrizedMagneticField
 *
 *  Magnetic Field engine wrapper for V. Karimaki's "off-axis expansion"
 *  of the TOSCA field version 85l_030919 (4 T)
 *  valid in the region r<1.2 m and |z|<3.0 m 
 *
 *  $Date: $
 *  $Revision: $
 *  \author N. Amapane - CERN
 */

#include "MagneticField/Engine/interface/MagneticField.h"

namespace edm { class ParameterSet; }

class OAE85lParametrizedMagneticField : public MagneticField {
 public:

  /// Constructor. The optional parameters are: 
  /// b0=field at centre, l=solenoid length, a=radius (m)
  OAE85lParametrizedMagneticField(float b0_ = 40.681, 
				  float a_ = 4.6430, 
				  float l_ = 15.284);

  /// Constructor. Parameters taken from a PSet
  OAE85lParametrizedMagneticField(const edm::ParameterSet& parameters);


  /// Destructor
  virtual ~OAE85lParametrizedMagneticField();
  
  GlobalVector inTesla (const GlobalPoint& gp) const;

  bool isDefined(const GlobalPoint& gp) const;

 private:
  bool trackerField(const GlobalPoint& gp, GlobalVector& bxyz) const ;

  void ffunkti(float u, float* ff) const;

  //phenomen. parameters:
  // b0=field at centre, l=solenoid length, a=radius (m) 
  float b0;
  float l;
  float a;

};
#endif