/*----------------------------------------------------------------------------
 * File:  ADTTM_TE_class.c
 *
 * Class:       Top Entity  (TE)
 * Component:   ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "ADTTestModel_sys_types.h"
#include "ADTTM_STR_bridge.h"
#include "ADTTM_classes.h"

/*
 * instance operation:  GetNumberOfLiefDevices
 */
i_t
ADTTM_TE_op_GetNumberOfLiefDevices( ADTTM_TE * self)
{
  ADTTM_ME * md=0;i_t numOfLD;Escher_ObjectSet_s mdSet_space={0}; Escher_ObjectSet_s * mdSet = &mdSet_space;
  /* ASSIGN numOfLD = 0 */
  XTUML_OAL_STMT_TRACE( 1, "ASSIGN numOfLD = 0" );
  numOfLD = 0;
  /* SELECT many mdSet RELATED BY self->ME[R1.child] */
  XTUML_OAL_STMT_TRACE( 1, "SELECT many mdSet RELATED BY self->ME[R1.child]" );
  Escher_ClearSet( mdSet );
  if ( 0 != self ) {
    Escher_CopySet( mdSet, &self->ME_R1_child );
  }
  /* FOR EACH md IN mdSet */
  XTUML_OAL_STMT_TRACE( 1, "FOR EACH md IN mdSet" );
  { Escher_Iterator_s itermd;
  ADTTM_ME * iimd;
  Escher_IteratorReset( &itermd, mdSet );
  while ( (iimd = (ADTTM_ME *)Escher_IteratorNext( &itermd )) != 0 ) {
    md = iimd; {
    Escher_ObjectSet_s ldSet_space={0}; Escher_ObjectSet_s * ldSet = &ldSet_space;
    /* SELECT many ldSet RELATED BY md->LD[R2.measurement] */
    XTUML_OAL_STMT_TRACE( 2, "SELECT many ldSet RELATED BY md->LD[R2.measurement]" );
    Escher_ClearSet( ldSet );
    if ( 0 != md ) {
      Escher_CopySet( ldSet, &md->LD_R2_measurement );
    }
    /* ASSIGN numOfLD = ( numOfLD + cardinality ldSet ) */
    XTUML_OAL_STMT_TRACE( 2, "ASSIGN numOfLD = ( numOfLD + cardinality ldSet )" );
    numOfLD = ( numOfLD + Escher_SetCardinality( ldSet ) );
    Escher_ClearSet( ldSet ); 
  }}}
  /* RETURN numOfLD */
  XTUML_OAL_STMT_TRACE( 1, "RETURN numOfLD" );
  {i_t xtumlOALrv = numOfLD;
  Escher_ClearSet( mdSet ); 
  return xtumlOALrv;}
  Escher_ClearSet( mdSet ); 
}


/*----------------------------------------------------------------------------
 * Operation action methods implementation for the following class:
 *
 * Class:      Top Entity  (TE)
 * Component:  ADTTM
 *--------------------------------------------------------------------------*/
/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static Escher_SetElement_s ADTTM_TE_container[ ADTTM_TE_MAX_EXTENT_SIZE ];
static ADTTM_TE ADTTM_TE_instances[ ADTTM_TE_MAX_EXTENT_SIZE ];
Escher_Extent_t pG_ADTTM_TE_extent = {
  {0}, {0}, &ADTTM_TE_container[ 0 ],
  (Escher_iHandle_t) &ADTTM_TE_instances,
  sizeof( ADTTM_TE ), 0, ADTTM_TE_MAX_EXTENT_SIZE
  };

