//#include "flash.h"
//
//uint8_t Flash_Type = 0;
//
//fsp_err_t QSPI_Flash_WaitForWriteEnd(void);
//
//void flash_init()
//{
//    fsp_err_t err = FSP_SUCCESS;
//    spi_flash_direct_transfer_t direct_command;
//
//    err = R_OSPI_B_Open (g_ospi0.p_ctrl, g_ospi0.p_cfg);
//    R_XSPI->LIOCFGCS_b[1].SDRSMPMD = 0x1;
//    /* Enable Reset */
//    memset(&direct_command, 0, sizeof(direct_command));
//    direct_command.command        = 0x66;
//    direct_command.command_length = 0x1;
//    err = R_OSPI_B_DirectTransfer (g_ospi0.p_ctrl, &direct_command, SPI_FLASH_DIRECT_TRANSFER_DIR_WRITE);
//    if(err!=FSP_SUCCESS){printf("err here %s:%d",__FILE__,__LINE__);}
//
//    /* Reset Device */
//    memset(&direct_command, 0, sizeof(direct_command));
//    direct_command.command        = 0x99;
//    direct_command.command_length = 0x1;
//    err = R_OSPI_B_DirectTransfer (g_ospi0.p_ctrl, &direct_command, SPI_FLASH_DIRECT_TRANSFER_DIR_WRITE);
//    if(err!=FSP_SUCCESS){printf("err here %s:%d",__FILE__,__LINE__);}
//
//    delay_ms(30);
//
//    /* Read Status Register Byte 2 */
//    memset(&direct_command, 0, sizeof(direct_command));
//    direct_command.command        = 0x35;
//    direct_command.command_length = 0x1;
//    direct_command.address        = 0x0;
//    direct_command.address_length = 0x0;
//    direct_command.dummy_cycles   = 0x0;
//    direct_command.data_length    = 0x1;
//    err = R_OSPI_B_DirectTransfer (g_ospi0.p_ctrl, &direct_command, SPI_FLASH_DIRECT_TRANSFER_DIR_READ);
//    if(err!=FSP_SUCCESS){printf("err here %s:%d",__FILE__,__LINE__);}
//
//    /* Set Write Enable for Volatile Status Register via 1S-1S-1S protocol */
//    memset(&direct_command, 0, sizeof(direct_command));
//    direct_command.command        = 0x50;
//    direct_command.command_length = 0x1;
//    err = R_OSPI_B_DirectTransfer (g_ospi0.p_ctrl, &direct_command, SPI_FLASH_DIRECT_TRANSFER_DIR_WRITE);
//    if(err!=FSP_SUCCESS){printf("err here %s:%d",__FILE__,__LINE__);}
//    msleep(1);
//
//    /* Set QE bit to 1 to enable Quad */
//    memset(&direct_command, 0, sizeof(direct_command));
//    direct_command.command        = 0x31;
//    direct_command.command_length = 0x1;
//    direct_command.data           = 0x02;
//    direct_command.data_length    = 0x1;
//    err = R_OSPI_B_DirectTransfer (g_ospi0.p_ctrl, &direct_command, SPI_FLASH_DIRECT_TRANSFER_DIR_WRITE);
//    if(err!=FSP_SUCCESS){printf("err here %s:%d",__FILE__,__LINE__);}
//
//    /* Read Status Register Byte 2 */
//    memset(&direct_command, 0, sizeof(direct_command));
//    direct_command.command        = 0x35;
//    direct_command.command_length = 0x1;
//    direct_command.address        = 0x0000;
//    direct_command.address_length = 0x0;
//    direct_command.dummy_cycles   = 0x0;
//    direct_command.data_length    = 0x1;
//    err = R_OSPI_B_DirectTransfer (g_ospi0.p_ctrl, &direct_command, SPI_FLASH_DIRECT_TRANSFER_DIR_READ);
//    if(err!=FSP_SUCCESS){printf("err here %s:%d",__FILE__,__LINE__);}
//
//    err = R_OSPI_B_SpiProtocolSet(g_ospi0.p_ctrl, SPI_FLASH_PROTOCOL_1S_4S_4S);
//    if(err!=FSP_SUCCESS){printf("err here %s:%d",__FILE__,__LINE__);}
//
//    /* Check Manufacture/Device ID via 1S-4S-4S protocol */
//    memset(&direct_command, 0, sizeof(direct_command));
//    direct_command.command        = 0x94;
//    direct_command.command_length = 0x1;
//    direct_command.address        = 0x000000;
//    direct_command.address_length = 0x3;
//    direct_command.dummy_cycles   = 0x6;
//    direct_command.data_length    = 0x2;
//    err = R_OSPI_B_DirectTransfer (g_ospi0.p_ctrl, &direct_command, SPI_FLASH_DIRECT_TRANSFER_DIR_READ);
//    if(err!=FSP_SUCCESS){printf("err here %s:%d",__FILE__,__LINE__);}
//    if(!((direct_command.data == 0x1F17) || (direct_command.data == 0x171F))){//For CPKCOR AT25SF128A
//
//        printf("err here %s:%d",__FILE__,__LINE__);
//    }
//}
//
//fsp_err_t QSPI_Flash_WaitForWriteEnd(void)
//{
//   spi_flash_status_t status = {.write_in_progress = true};
//   int32_t time_out          = (INT32_MAX);
//   fsp_err_t err             = FSP_SUCCESS;
//   do{
//      /* Get status from QSPI flash device */
//      err = R_OSPI_B_StatusGet(&g_ospi0_ctrl, &status);
//      if (FSP_SUCCESS != err){
//            printf("R_QSPI_StatusGet Failed\r\n");
//            return err;
//      }
//      /* Decrement time out to avoid infinite loop in case of consistent failure */
//      --time_out;
//      if (RESET_VALUE >= time_out){
//            printf("\r\n ** Timeout : No result from QSPI flash status register ** \r\n");
//            return FSP_ERR_TIMEOUT;
//      }
//   }while (false != status.write_in_progress);
//   return err;
//}
//
///**
//* @brief  ����FLASH����
//* @param  SectorAddr锛�瑕����ょ�����哄�板��
//* @retval ��
//*/
//void QSPI_Flash_SectorErase(uint32_t adress)
//{
//   spi_flash_direct_transfer_t direct_command;
//   memset(&direct_command, 0, sizeof(direct_command));
//   unsigned char data[4];
//   data[1] = 0x20;     //erase_command
//   data[2] = (uint8_t)(adress >> 16);
//   data[3] = (uint8_t)(adress >> 8);
//   data[4] = (uint8_t)(adress);
//   direct_command.command        = 0x0;
//   direct_command.command_length = 0x1;
//   R_OSPI_B_DirectTransfer (g_ospi0.p_ctrl, &direct_command, SPI_FLASH_DIRECT_TRANSFER_DIR_WRITE);
//   R_OSPI_B_DirectWrite (g_ospi0.p_ctrl, data, 4, false);
//   QSPI_Flash_WaitForWriteEnd();
//}
//
///**
//* @brief  瀵�FLASH��椤靛���ユ�版��锛�璋��ㄦ���芥�板���ユ�版������瑕������ゆ����
//* @param  pBuffer锛�瑕����ユ�版��������
//* @param  WriteAddr锛����ュ�板��
//* @param  NumByteToWrite锛����ユ�版���垮害锛�蹇�椤诲�浜�绛�浜�椤靛ぇ灏�
//* @retval ��
//*/
//void QSPI_Flash_PageWrite(uint8_t *pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
//{
//    R_OSPI_B_DirectWrite(g_ospi0.p_ctrl, pBuffer, WriteAddr, NumByteToWrite);
//   QSPI_Flash_WaitForWriteEnd();
//}
//
//
//
//
//
