/*----------------------------------------------------------------------------
 * File:  ADTTM_OOD_class.c
 *
 * Class:       Order of Device  (OOD)
 * Component:   ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "ADTTestModel_sys_types.h"
#include "ADTTM_STR_bridge.h"
#include "ADTTM_classes.h"

/* Note:  Link LD to LD across R3.'right' using OOD not needed.  */

/* Note:  Unlink LD from LD across R3.'right' USING OOD not needed.  */
/* Note:  Link LD to LD across R3.'left' using OOD not needed.  */

/* Note:  Unlink LD from LD across R3.'left' USING OOD not needed.  */
/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static Escher_SetElement_s ADTTM_OOD_container[ ADTTM_OOD_MAX_EXTENT_SIZE ];
static ADTTM_OOD ADTTM_OOD_instances[ ADTTM_OOD_MAX_EXTENT_SIZE ];
Escher_Extent_t pG_ADTTM_OOD_extent = {
  {0}, {0}, &ADTTM_OOD_container[ 0 ],
  (Escher_iHandle_t) &ADTTM_OOD_instances,
  sizeof( ADTTM_OOD ), 0, ADTTM_OOD_MAX_EXTENT_SIZE
  };

