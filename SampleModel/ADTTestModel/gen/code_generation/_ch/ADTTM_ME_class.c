/*----------------------------------------------------------------------------
 * File:  ADTTM_ME_class.c
 *
 * Class:       Middle Entity  (ME)
 * Component:   ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "ADTTestModel_sys_types.h"
#include "ADTTM_STR_bridge.h"
#include "ADTTM_classes.h"

/*
 * instance operation:  Command
 */
void
ADTTM_ME_op_Command( ADTTM_ME * self, c_t p_order[ESCHER_SYS_MAX_STRING_LEN] )
{

}

/*
 * RELATE TE TO ME ACROSS R1
 */
void
ADTTM_ME_R1_Link_child( ADTTM_TE * part, ADTTM_ME * form )
{
  if ( (part == 0) || (form == 0) ) {
    XTUML_EMPTY_HANDLE_TRACE( "ME", "ADTTM_ME_R1_Link_child" );
    return;
  }
  form->TopEntityId = part->TopEntityId;
  form->TE_R1 = part;
  Escher_SetInsertElement( &part->ME_R1_child, (Escher_ObjectSet_s *) form );
}

/*
 * UNRELATE TE FROM ME ACROSS R1
 */
void
ADTTM_ME_R1_Unlink_child( ADTTM_TE * part, ADTTM_ME * form )
{
  if ( (part == 0) || (form == 0) ) {
    XTUML_EMPTY_HANDLE_TRACE( "ME", "ADTTM_ME_R1_Unlink_child" );
    return;
  }
  form->TopEntityId = 0;
  form->TE_R1 = 0;
  Escher_SetRemoveElement( &part->ME_R1_child, (Escher_ObjectSet_s *) form );
}

/*----------------------------------------------------------------------------
 * Operation action methods implementation for the following class:
 *
 * Class:      Middle Entity  (ME)
 * Component:  ADTTM
 *--------------------------------------------------------------------------*/
/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static Escher_SetElement_s ADTTM_ME_container[ ADTTM_ME_MAX_EXTENT_SIZE ];
static ADTTM_ME ADTTM_ME_instances[ ADTTM_ME_MAX_EXTENT_SIZE ];
Escher_Extent_t pG_ADTTM_ME_extent = {
  {0}, {0}, &ADTTM_ME_container[ 0 ],
  (Escher_iHandle_t) &ADTTM_ME_instances,
  sizeof( ADTTM_ME ), 0, ADTTM_ME_MAX_EXTENT_SIZE
  };

