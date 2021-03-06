/*
   Copyright (c) 2015 Broadcom Corporation
   All Rights Reserved

    <:label-BRCM:2015:DUAL/GPL:standard

    Unless you and Broadcom execute a separate written software license
    agreement governing use of this software, this software is licensed
    to you under the terms of the GNU General Public License version 2
    (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
    with the following added to such license:

       As a special exception, the copyright holders of this software give
       you permission to link this software with independent modules, and
       to copy and distribute the resulting executable under terms of your
       choice, provided that you also meet, for each linked independent
       module, the terms and conditions of the license of that module.
       An independent module is a module which is not derived from this
       software.  The special exception does not apply to any modifications
       of the software.

    Not withstanding the above, under no circumstances may you combine
    this software in any way with any other Broadcom software provided
    under a license other than the GPL, without Broadcom's express prior
    written consent.

:>
*/

#include "drivers_common_ag.h"
#include "pmi_ag.h"
bdmf_error_t ag_drv_pmi_lp_0_set(bdmf_boolean pmi_lp_en, bdmf_boolean pmi_lp_write)
{
    uint32_t reg_lp_0=0;

#ifdef VALIDATE_PARMS
    if((pmi_lp_write >= _1BITS_MAX_VAL_) ||
       (pmi_lp_en >= _1BITS_MAX_VAL_))
    {
        bdmf_trace("ERROR driver %s:%u| err=%s (%d)\n", __FILE__, __LINE__, bdmf_strerror(BDMF_ERR_RANGE), BDMF_ERR_RANGE);
        return BDMF_ERR_RANGE;
    }
#endif

    reg_lp_0 = RU_FIELD_SET(0, PMI, LP_0, PMI_LP_WRITE, reg_lp_0, pmi_lp_write);
    reg_lp_0 = RU_FIELD_SET(0, PMI, LP_0, PMI_LP_EN, reg_lp_0, pmi_lp_en);

    RU_REG_WRITE(0, PMI, LP_0, reg_lp_0);

    return BDMF_ERR_OK;
}

bdmf_error_t ag_drv_pmi_lp_0_get(bdmf_boolean *pmi_lp_en, bdmf_boolean *pmi_lp_write)
{
    uint32_t reg_lp_0=0;

#ifdef VALIDATE_PARMS
    if(!pmi_lp_write || !pmi_lp_en)
    {
        bdmf_trace("ERROR driver %s:%u| err=%s (%d)\n", __FILE__, __LINE__, bdmf_strerror(BDMF_ERR_PARM), BDMF_ERR_PARM);
        return BDMF_ERR_PARM;
    }
#endif

    RU_REG_READ(0, PMI, LP_0, reg_lp_0);

    *pmi_lp_write = RU_FIELD_GET(0, PMI, LP_0, PMI_LP_WRITE, reg_lp_0);
    *pmi_lp_en = RU_FIELD_GET(0, PMI, LP_0, PMI_LP_EN, reg_lp_0);

    return BDMF_ERR_OK;
}

bdmf_error_t ag_drv_pmi_lp_1_set(uint32_t pmi_lp_addr)
{
    uint32_t reg_lp_1=0;

#ifdef VALIDATE_PARMS
#endif

    reg_lp_1 = RU_FIELD_SET(0, PMI, LP_1, PMI_LP_ADDR, reg_lp_1, pmi_lp_addr);

    RU_REG_WRITE(0, PMI, LP_1, reg_lp_1);

    return BDMF_ERR_OK;
}

bdmf_error_t ag_drv_pmi_lp_1_get(uint32_t *pmi_lp_addr)
{
    uint32_t reg_lp_1=0;

#ifdef VALIDATE_PARMS
    if(!pmi_lp_addr)
    {
        bdmf_trace("ERROR driver %s:%u| err=%s (%d)\n", __FILE__, __LINE__, bdmf_strerror(BDMF_ERR_PARM), BDMF_ERR_PARM);
        return BDMF_ERR_PARM;
    }
#endif

    RU_REG_READ(0, PMI, LP_1, reg_lp_1);

    *pmi_lp_addr = RU_FIELD_GET(0, PMI, LP_1, PMI_LP_ADDR, reg_lp_1);

    return BDMF_ERR_OK;
}

bdmf_error_t ag_drv_pmi_lp_2_set(uint16_t pmi_lp_wrdata, uint16_t pmi_lp_maskdata)
{
    uint32_t reg_lp_2=0;

#ifdef VALIDATE_PARMS
#endif

    reg_lp_2 = RU_FIELD_SET(0, PMI, LP_2, PMI_LP_MASKDATA, reg_lp_2, pmi_lp_maskdata);
    reg_lp_2 = RU_FIELD_SET(0, PMI, LP_2, PMI_LP_WRDATA, reg_lp_2, pmi_lp_wrdata);

    RU_REG_WRITE(0, PMI, LP_2, reg_lp_2);

    return BDMF_ERR_OK;
}

bdmf_error_t ag_drv_pmi_lp_2_get(uint16_t *pmi_lp_wrdata, uint16_t *pmi_lp_maskdata)
{
    uint32_t reg_lp_2=0;

#ifdef VALIDATE_PARMS
    if(!pmi_lp_maskdata || !pmi_lp_wrdata)
    {
        bdmf_trace("ERROR driver %s:%u| err=%s (%d)\n", __FILE__, __LINE__, bdmf_strerror(BDMF_ERR_PARM), BDMF_ERR_PARM);
        return BDMF_ERR_PARM;
    }
#endif

    RU_REG_READ(0, PMI, LP_2, reg_lp_2);

    *pmi_lp_maskdata = RU_FIELD_GET(0, PMI, LP_2, PMI_LP_MASKDATA, reg_lp_2);
    *pmi_lp_wrdata = RU_FIELD_GET(0, PMI, LP_2, PMI_LP_WRDATA, reg_lp_2);

    return BDMF_ERR_OK;
}

bdmf_error_t ag_drv_pmi_lp_3_get(bdmf_boolean *pmi_lp_err, bdmf_boolean *pmi_lp_ack, uint16_t *pmi_lp_rddata)
{
    uint32_t reg_lp_3=0;

#ifdef VALIDATE_PARMS
    if(!pmi_lp_rddata || !pmi_lp_ack || !pmi_lp_err)
    {
        bdmf_trace("ERROR driver %s:%u| err=%s (%d)\n", __FILE__, __LINE__, bdmf_strerror(BDMF_ERR_PARM), BDMF_ERR_PARM);
        return BDMF_ERR_PARM;
    }
#endif

    RU_REG_READ(0, PMI, LP_3, reg_lp_3);

    *pmi_lp_rddata = RU_FIELD_GET(0, PMI, LP_3, PMI_LP_RDDATA, reg_lp_3);
    *pmi_lp_ack = RU_FIELD_GET(0, PMI, LP_3, PMI_LP_ACK, reg_lp_3);
    *pmi_lp_err = RU_FIELD_GET(0, PMI, LP_3, PMI_LP_ERR, reg_lp_3);

    return BDMF_ERR_OK;
}

