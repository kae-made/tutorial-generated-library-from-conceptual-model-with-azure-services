/*----------------------------------------------------------------------------
 * File:  ADTTM_STR_bridge.h
 *
 * Description:
 * Methods for bridging to an external entity.
 *
 * External Entity:  String Utility (STR)
 * @constructor(new:Kae.DomainModel.Csharp.Framework.ExternalEntity.STR.STRImpl,namespace:Kae.DomainModel.Csharp.Framework.ExternalEntity.STR);builtin(true)
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef ADTTM_STR_BRIDGE_H
#define ADTTM_STR_BRIDGE_H
#ifdef	__cplusplus
extern	"C"	{
#endif

#include "ADTTestModel_sys_types.h"
i_t ADTTM_STR_charindex( c_t[ESCHER_SYS_MAX_STRING_LEN], c_t[ESCHER_SYS_MAX_STRING_LEN], const i_t );
c_t * ADTTM_STR_concat( c_t[ESCHER_SYS_MAX_STRING_LEN], c_t[ESCHER_SYS_MAX_STRING_LEN], c_t[ESCHER_SYS_MAX_STRING_LEN] );
c_t * ADTTM_STR_left( c_t[ESCHER_SYS_MAX_STRING_LEN], c_t[ESCHER_SYS_MAX_STRING_LEN], const i_t );
i_t ADTTM_STR_len( c_t[ESCHER_SYS_MAX_STRING_LEN] );
c_t * ADTTM_STR_lower( c_t[ESCHER_SYS_MAX_STRING_LEN], c_t[ESCHER_SYS_MAX_STRING_LEN] );
c_t * ADTTM_STR_ltrim( c_t[ESCHER_SYS_MAX_STRING_LEN], c_t[ESCHER_SYS_MAX_STRING_LEN] );
c_t * ADTTM_STR_match( c_t[ESCHER_SYS_MAX_STRING_LEN], c_t[ESCHER_SYS_MAX_STRING_LEN], c_t[ESCHER_SYS_MAX_STRING_LEN] );
c_t * ADTTM_STR_replace( c_t[ESCHER_SYS_MAX_STRING_LEN], c_t[ESCHER_SYS_MAX_STRING_LEN], c_t[ESCHER_SYS_MAX_STRING_LEN], c_t[ESCHER_SYS_MAX_STRING_LEN] );
c_t * ADTTM_STR_replicate( c_t[ESCHER_SYS_MAX_STRING_LEN], c_t[ESCHER_SYS_MAX_STRING_LEN], const i_t );
c_t * ADTTM_STR_reverse( c_t[ESCHER_SYS_MAX_STRING_LEN], c_t[ESCHER_SYS_MAX_STRING_LEN] );
c_t * ADTTM_STR_right( c_t[ESCHER_SYS_MAX_STRING_LEN], c_t[ESCHER_SYS_MAX_STRING_LEN], const i_t );
c_t * ADTTM_STR_rtrim( c_t[ESCHER_SYS_MAX_STRING_LEN], c_t[ESCHER_SYS_MAX_STRING_LEN] );
c_t * ADTTM_STR_substring( c_t[ESCHER_SYS_MAX_STRING_LEN], c_t[ESCHER_SYS_MAX_STRING_LEN], const i_t, const i_t );
c_t * ADTTM_STR_trim( c_t[ESCHER_SYS_MAX_STRING_LEN], c_t[ESCHER_SYS_MAX_STRING_LEN] );
c_t * ADTTM_STR_upper( c_t[ESCHER_SYS_MAX_STRING_LEN], c_t[ESCHER_SYS_MAX_STRING_LEN] );
bool ADTTM_STR_tobool( c_t[ESCHER_SYS_MAX_STRING_LEN] );
i_t ADTTM_STR_tointeger( c_t[ESCHER_SYS_MAX_STRING_LEN] );
r_t ADTTM_STR_toreal( c_t[ESCHER_SYS_MAX_STRING_LEN] );
Escher_Date_t ADTTM_STR_todate( c_t[ESCHER_SYS_MAX_STRING_LEN] );
c_t * ADTTM_STR_frombool( c_t[ESCHER_SYS_MAX_STRING_LEN], const bool );
c_t * ADTTM_STR_frominteger( c_t[ESCHER_SYS_MAX_STRING_LEN], const i_t );
c_t * ADTTM_STR_fromreal( c_t[ESCHER_SYS_MAX_STRING_LEN], const r_t );
c_t * ADTTM_STR_fromdate( c_t[ESCHER_SYS_MAX_STRING_LEN], Escher_Date_t );
c_t * ADTTM_STR_newguid( c_t[ESCHER_SYS_MAX_STRING_LEN] );

#ifdef	__cplusplus
}
#endif
#endif   /* ADTTM_STR_BRIDGE_H */
