/*----------------------------------------------------------------------------
 * File:  ADTTM_SC1_class.c
 *
 * Class:       SubClass1  (SC1)
 * Component:   ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "ADTTestModel_sys_types.h"
#include "ADTTM_STR_bridge.h"
#include "ADTTM_classes.h"


/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static Escher_SetElement_s ADTTM_SC1_container[ ADTTM_SC1_MAX_EXTENT_SIZE ];
static ADTTM_SC1 ADTTM_SC1_instances[ ADTTM_SC1_MAX_EXTENT_SIZE ];
Escher_Extent_t pG_ADTTM_SC1_extent = {
  {0}, {0}, &ADTTM_SC1_container[ 0 ],
  (Escher_iHandle_t) &ADTTM_SC1_instances,
  sizeof( ADTTM_SC1 ), 0, ADTTM_SC1_MAX_EXTENT_SIZE
  };

