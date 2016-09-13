/*
****************************************
**  Copyright  (C)  W.ch  1999-2007   **
**  Web:  http://www.winchiphead.com  **
****************************************
**  USB Host File Module      @CH375  **
****************************************
*/
/* CH375 �����ļ�ϵͳ�ӿ�ģ�� */
/* ֧��: FAT12/FAT16/FAT32 */
/* U���ļ���дģ��C����ͷ�ļ� */

#ifndef __CH375HM_H__
#define __CH375HM_H__

#define CH375HM_VER				0x30	/* ��ǰģ��汾 */

/* ********************************************************************************************************************* */
/* ���صĲ���״̬�� */
/* �������¼�֪ͨ״̬��,��⵽��ǰU���Ѿ����ӻ����Ѿ��Ͽ�,������Ϊ����״̬�� */
#define	ERR_USB_CONNECT			0x15	/* ��⵽USB�豸�����¼�,�����Ѿ����� */
#define ERR_DISK_DISCON			0x82	/* ��⵽USB�豸�����¼�,�����Ѿ��Ͽ�,���ߴ�����δ���� */
/* ����0XH����USB�豸��ʽ�Ĳ���״̬����,��CH375����,��USB�豸ģʽ���ж�״̬ */
#define	ERR_USB_DAT_DOWN		0x02	/* USB�豸ģʽ: �����´��ɹ�,��λ���´��������Ѿ���ģ���� */
#define	ERR_USB_DAT_UP			0x0A	/* USB�豸ģʽ: �����ϴ��ɹ�,ģ���е��ϴ������Ѿ�����λ��ȡ�� */
/* �����ǽ׶��Ե�״̬��,�����������ݽ���,�������յĲ���״̬ */
#define	USB_INT_DISK_READ		0x1D	/* USB�洢�������ݿ�,ֻ����CMD_FileRead����,�������ݶ��� */
#define	USB_INT_DISK_WRITE		0x1E	/* USB�洢��д���ݿ�,ֻ����CMD_FileWrite����,��������д�� */
#define	USB_INT_DISK_RETRY		0xEE	/* USB�洢����д���ݿ�ʧ������,ֻ����CMD_FileRead�����CMD_FileRead����,����ʧ������ */
/* USB_INT_DISK_RETRY����״̬��Ҫ���û��˳���ظ��ļ����ݻ�����ָ��,�Ա����·��ͻ��߽����ļ�����,
   ��USB_INT_DISK_RETRY����״̬��֮���û��˳����յ������ֽڵ�����,Ҳ����һ��16λ������,ָ����Ҫ�ظ�ָ����ֽ���,���ʱ���ֽ���ǰ,С��ʱ���ֽ���ǰ */
/* ����״̬�� */
#define ERR_SUCCESS				0x00	/* �����ɹ� */
#define ERR_CH375_ERROR			0x81	/* CH375Ӳ������,������Ҫ��λCH375 */
#define ERR_STATUS_ERR			0x83	/* ����״̬����,�����������ӻ��߶Ͽ����� */
#define ERR_MBR_ERROR			0x91	/* ���̵���������¼��Ч,���ܴ�����δ����������δ��ʽ�� */
#define ERR_TYPE_ERROR			0x92	/* ���̷������Ͳ�֧��,ֻ֧��FAT12/FAT16/BigDOS/FAT32,��Ҫ�ɴ��̹����������·��� */
#define ERR_BPB_ERROR			0xA1	/* ������δ��ʽ��,���߲�������,��Ҫ��WINDOWS����Ĭ�ϲ������¸�ʽ�� */
#define ERR_TOO_LARGE			0xA2	/* ���̷�������ʽ��������������4GB,������������250GB,��Ҫ��WINDOWS����Ĭ�ϲ������¸�ʽ�� */
#define ERR_FAT_ERROR			0xA3	/* ���̵��ļ�ϵͳ��֧��,ֻ֧��FAT12/FAT16/FAT32,��Ҫ��WINDOWS����Ĭ�ϲ������¸�ʽ�� */
#define ERR_DISK_FULL			0xB1	/* �����ļ�̫��,ʣ��ռ�̫�ٻ����Ѿ�û��,��Ҫ�������� */
#define ERR_FDT_OVER			0xB2	/* Ŀ¼���ļ�̫��,û�п��е�Ŀ¼��,FAT12/FAT16��Ŀ¼�µ��ļ���Ӧ������500��,��Ҫ�������� */
#define ERR_MISS_DIR			0xB3	/* ָ��·����ĳ����Ŀ¼û���ҵ�,������Ŀ¼���ƴ��� */
#define ERR_FILE_CLOSE			0xB4	/* �ļ��Ѿ��ر�,�����Ҫʹ��,Ӧ�����´��ļ� */
#define ERR_OPEN_DIR			0x41	/* ָ��·����Ŀ¼���� */
#define ERR_MISS_FILE			0x42	/* ָ��·�����ļ�û���ҵ�,�������ļ����ƴ��� */
#define ERR_FOUND_NAME			0x43	/* ��������ͨ�����ƥ����ļ���,�ļ�����������·�������������,�����Ҫʹ��,Ӧ�ô򿪸��ļ� */
#define	ERR_USB_DISK_ERR		0x1F	/* USB�洢������ʧ��,�ڳ�ʼ��ʱ������USB�洢����֧��,�ڶ�д�����п����Ǵ����𻵻����Ѿ��Ͽ� */
/* ����������δ����,���Է�������CMD_QueryStatus��ѯģ��״̬������ */

/* ********************************************************************************************************************* */
/* ���̼��ļ�״̬,������CMD_PARAM.Status.mDiskStatus */
#define DISK_UNKNOWN			0x00	/* ��δ��ʼ��,δ֪״̬ */
#define DISK_DISCONNECT			0x01	/* ����û�����ӻ����Ѿ��Ͽ� */
#define DISK_CONNECT			0x02	/* �����Ѿ�����,������δ��ʼ�������޷�ʶ��ô��� */
#define DISK_MOUNTED			0x03	/* �����Ѿ���ʼ���ɹ�,������δ�����ļ�ϵͳ�����ļ�ϵͳ��֧�� */
#define DISK_READY				0x10	/* �Ѿ��������̵��ļ�ϵͳ�����ܹ�֧�� */
#define DISK_OPEN_ROOT			0x12	/* �Ѿ��򿪸�Ŀ¼,����ģʽ,ֻ��������Ϊ��λ��дĿ¼������,ʹ�ú����ر�,ע��FAT12/FAT16��Ŀ¼�ǹ̶����� */
#define DISK_OPEN_DIR			0x13	/* �Ѿ�����Ŀ¼,����ģʽ,ֻ��������Ϊ��λ��дĿ¼������ */
#define DISK_OPEN_FILE			0x14	/* �Ѿ����ļ�,����ģʽ,����������Ϊ��λ�������ݶ�д */
#define DISK_OPEN_FILE_B		0x15	/* �Ѿ����ļ�,�ֽ�ģʽ,�������ֽ�Ϊ��λ�������ݶ�д */

/* ********************************************************************************************************************* */
/* FAT���ͱ�־,������CMD_PARAM.Query.mDiskFat */
#define DISK_FS_UNKNOWN			0		/* δ֪���ļ�ϵͳ */
#define DISK_FAT12				1		/* FAT12�ļ�ϵͳ */
#define DISK_FAT16				2		/* FAT16�ļ�ϵͳ */
#define DISK_FAT32				3		/* FAT32�ļ�ϵͳ */

/* ********************************************************************************************************************* */
/* �ļ�����,������CMD_PARAM.Modify.mFileAttr */
#define ATTR_READ_ONLY			0x01	/* �ļ�Ϊֻ������ */
#define ATTR_HIDDEN				0x02	/* �ļ�Ϊ�������� */
#define ATTR_SYSTEM				0x04	/* �ļ�Ϊϵͳ���� */
#define ATTR_VOLUME_ID			0x08	/* ���� */
#define ATTR_DIRECTORY			0x10	/* ��Ŀ¼ */
#define ATTR_ARCHIVE			0x20	/* �ļ�Ϊ�浵���� */
#define ATTR_LONG_NAME			( ATTR_READ_ONLY | ATTR_HIDDEN | ATTR_SYSTEM | ATTR_VOLUME_ID )
/* �ļ����� unsigned char */
/* bit0 bit1 bit2 bit3 bit4 bit5 bit6 bit7 */
/*  ֻ   ��   ϵ   ��   Ŀ   ��   δ����   */
/*  ��   ��   ͳ   ��   ¼   ��            */
/* �ļ�ʱ�� unsigned short,������CMD_PARAM.Modify.mFileTime */
/* Time = (Hour<<11) + (Minute<<5) + (Second>>1) */
#define MAKE_FILE_TIME( h, m, s )	( (h<<11) + (m<<5) + (s>>1) )	/* ����ָ��ʱ������ļ�ʱ������ */
/* �ļ����� unsigned short,������CMD_PARAM.Modify.mFileDate */
/* Date = ((Year-1980)<<9) + (Month<<5) + Day */
#define MAKE_FILE_DATE( y, m, d )	( ((y-1980)<<9) + (m<<5) + d )	/* ����ָ�������յ��ļ��������� */

/* ********************************************************************************************************************* */
/* �ļ���,������CMD_PARAM.?.mPathName */
#define PATH_WILDCARD_CHAR		0x2A	/* ·������ͨ��� '*' */
#define PATH_SEPAR_CHAR1		0x5C	/* ·�����ķָ��� '\' */
#define PATH_SEPAR_CHAR2		0x2F	/* ·�����ķָ��� '/' */
#ifndef MAX_PATH_LEN
#define MAX_PATH_LEN			65		/* ���·������,������б�ָܷ�����С���������Լ�·��������00H,���ڷ�ʽ�����ֵΪ62 */
#endif
#if		MAX_PATH_LEN		>	65
#undef	MAX_PATH_LEN
#define MAX_PATH_LEN			65
#endif
#ifndef MAX_BYTE_IO
#define MAX_BYTE_IO				( MAX_PATH_LEN - 1 )	/* ���ֽ�Ϊ��λ���ζ�д�ļ�ʱ����󳤶�,�����ó��ȿ��Էֶ�ζ�д,���ڷ�ʽ�����ֵΪ61 */
#endif
#if		MAX_BYTE_IO			>	64
#undef	MAX_BYTE_IO
#define	MAX_BYTE_IO				64
#endif

/* ********************************************************************************************************************* */
/* �ⲿ������ */
#define	CMD_QueryStatus			0x60	/* ��ѯ��ǰģ���״̬ */
#define	CMD_DiskQuery			0x61	/* ��ѯ������Ϣ */
#define	CMD_FileEnumer			0x63	/* ö���ļ�,�����ļ��� */
#define	CMD_FileOpen			0x64	/* ���ļ� */
#define	CMD_FileCreate			0x65	/* �½��ļ�����,����ļ��Ѿ���������ɾ�������½� */
#define	CMD_FileErase			0x66	/* ɾ���ļ����ر� */
#define	CMD_FileClose			0x67	/* �رյ�ǰ�ļ� */
#define	CMD_FileQuery			0x68	/* ��ѯ��ǰ�ļ�����Ϣ */
#define	CMD_FileModify			0x69	/* ��ѯ�����޸ĵ�ǰ�ļ�����Ϣ */
#define	CMD_FileLocate			0x6A	/* �ƶ���ǰ�ļ�ָ�� */
#define	CMD_FileRead			0x6B	/* �ӵ�ǰ�ļ���ȡ���� */
#define	CMD_FileWrite			0x6C	/* ��ǰ�ļ�д������ */
#define	CMD_ByteLocate			0x7A	/* ���ֽ�Ϊ��λ�ƶ���ǰ�ļ�ָ�� */
#define	CMD_ByteRead			0x7B	/* ���ֽ�Ϊ��λ�ӵ�ǰ�ļ���ȡ���ݿ� */
#define	CMD_ByteWrite			0x7C	/* ���ֽ�Ϊ��λ��ǰ�ļ�д�����ݿ� */
#define	CMD_BulkOnlyCmd			0x70	/* ִ�л���BulkOnlyЭ������� */
#define	CMD_DiskReady			0x71	/* ��ѯ�����Ƿ�׼���� */
#define	CMD_DiskSize			0x72	/* ��ѯ�������� */
#define	CMD_FileDirInfo			0x75	/* ��ȡ��ǰ�Ѵ��ļ���Ŀ¼��Ϣ */
#define	CMD_DirCreate			0x76	/* �½�Ŀ¼����,���Ŀ¼�Ѿ�������ֱ�Ӵ� */
#define	CMD_FileReadLast		0x77	/* �ӵ�ǰ�ļ���β����ȡ����һ���������ȵ��������� */
#define	CMD_SetFileSize			0x78	/* �޸�ģ��ϵͳ���ӳ������ļ����ȱ��� */
#define	CMD_StreamRead			0x7E	/* ������ģʽ���ļ�,ֻ֧�ִ���,ֻ֧���ı� */
#define	CMD_StreamWrite			0x7F	/* ������ģʽд�ļ�,ֻ֧�ִ���,ֻ֧���ı� */
/* USB�豸��ʽ������ */
#define	CMD_SetUsbId			0x12	/* USB�豸ģʽ: ����USB�豸�ĳ���VID�Ͳ�ƷPID */
#define	CMD_SetUsbMode			0x15	/* USB�豸ģʽ: ����USB����/�豸����ģʽ,ֻ֧�ִ��� */
#define	CMD_ReadUsbData			0x28	/* USB�豸ģʽ: ��ģ��������´��˵��ȡ���ݿ� */
#define	CMD_WriteUsbData		0x2B	/* USB�豸ģʽ: ��ģ��������ϴ��˵�д�����ݿ� */
/* ���������� */
#define	CMD_GetVer				0x0A	/* ��ȡ��ǰģ��İ汾�� */
#define	CMD_ResetInit			0x0B	/* ��λ�����³�ʼ��CH375�Լ�ģ�� */
#define	CMD_BaudRate			0xA5	/* ���ô���ͨѶ������ */
#define	CMD_SetupModule			0xA6	/* ����ģ������ */
#define	CMD_DirectWrCmd			0xB9	/* ֱ�Ӵ��ݸ�CH375,д���� */
#define	CMD_DirectRdDat			0xB5	/* ֱ�Ӵ��ݸ�CH375,������ */
#define	CMD_DirectWrDat			0xB6	/* ֱ�Ӵ��ݸ�CH375,д���� */
#define	CMD_GetStringSN			0xA0	/* ��ȡ��Ʒ���к��ַ��� */

/* ********************************************************************************************************************* */
/* �ⲿ������� */
typedef union _CMD_PARAM {
	struct {
		unsigned char	mBuffer[ MAX_PATH_LEN ];
	} Other;
	struct {
		unsigned long	mDiskSizeSec;			/* ����: �����������̵��������� */
		unsigned long	mTotalSector;			/* ����: ��ǰ�߼��̵��������� */
		unsigned long	mFreeSector;			/* ����: ��ǰ�߼��̵�ʣ�������� */
		unsigned char	mDiskFat;				/* ����: ��ǰ�߼��̵�FAT���� */
	} Query;									/* CMD_DiskQuery, ��ѯ������Ϣ */
	struct {
		unsigned char	mPathName[ MAX_PATH_LEN ];	/* �������: ·��: [�̷�,ð��,б��,Ŀ¼�������ļ�������չ��...,������00H], �����̷���ð�ſ���ʡ��, ����"C:\DIR1.EXT\DIR2\FILENAME.EXT",00H */
	} Open;										/* CMD_FileOpen, ���ļ� */
	struct {
		unsigned char	mPathName[ MAX_PATH_LEN ];	/* �������: ·��: [�̷�,ð��,б��,Ŀ¼�������ļ�������չ��(��ͨ���*)...,ö�����], �����̷���ð�ſ���ʡ��, ����"C:\DIR1.EXT\DIR2\FILE*",00H */
	} Enumer;									/* CMD_FileEnumer, ö���ļ�,�����ļ��� */
	struct {
		unsigned char	mUpdateLen;				/* �������: �Ƿ��������³���: 0��ֹ,1���� */
	} Close;									/* CMD_FileClose, �رյ�ǰ�ļ� */
	struct {
		unsigned char	mPathName[ MAX_PATH_LEN ];	/* �������: ·��: [�̷�,ð��,б��,Ŀ¼�������ļ�������չ��...,������00H], �����̷���ð�ſ���ʡ��, ����"C:\DIR1.EXT\DIR2\FILENAME.EXT",00H */
	} Create;									/* CMD_FileCreate, �½��ļ�����,����ļ��Ѿ���������ɾ�������½� */
	struct {
		unsigned char	mPathName[ MAX_PATH_LEN ];	/* �������: ·��: [�̷�,ð��,б��,Ŀ¼�������ļ�������չ��...,������00H], �����̷���ð�ſ���ʡ��, ����"C:\DIR1.EXT\DIR2\FILENAME.EXT",00H */
	} Erase;									/* CMD_FileErase, ɾ���ļ����ر� */
	struct {
		unsigned long	mFileSize;				/* �������: �µ��ļ�����,Ϊ0FFFFFFFFH���޸�, ����: ԭ���� */
		unsigned short	mFileDate;				/* �������: �µ��ļ�����,Ϊ0FFFFH���޸�, ����: ԭ���� */
		unsigned short	mFileTime;				/* �������: �µ��ļ�ʱ��,Ϊ0FFFFH���޸�, ����: ԭʱ�� */
		unsigned char	mFileAttr;				/* �������: �µ��ļ�����,Ϊ0FFH���޸�, ����: ԭ���� */
	} Modify;									/* CMD_FileQuery, ��ѯ��ǰ�ļ�����Ϣ; CMD_FileModify, ��ѯ�����޸ĵ�ǰ�ļ�����Ϣ */
	struct {
		unsigned long	mSectorOffset;			/* �������: ����ƫ��,0���ƶ����ļ�ͷ,0FFFFFFFFH���ƶ����ļ�β, ����: ��ǰ�ļ�ָ���Ӧ�ľ�������������, 0FFFFFFFFH���ѵ��ļ�β */
	} Locate;									/* CMD_FileLocate, �ƶ���ǰ�ļ�ָ�� */
	struct {
		unsigned char	mSectorCount;			/* �������: ��ȡ������, ����: ʵ�ʶ�ȡ������ */
	} Read;										/* CMD_FileRead, �ӵ�ǰ�ļ���ȡ���� */
	struct {
		unsigned char	mSectorCount;			/* �������: д��������, ����: ʵ��д�������� */
	} Write;									/* CMD_FileWrite, ��ǰ�ļ�д������ */
	struct {
		unsigned long	mDiskSizeSec;			/* ����: �����������̵��������� */
	} DiskSize;									/* CMD_DiskSize, ��ѯ�������� */
	struct {
		unsigned long	mByteOffset;			/* �������: ���ֽ�Ϊ��λ��ƫ����, ���ֽ�Ϊ��λ���ļ�ָ��, ����: ��ǰ�ļ�ָ���Ӧ�ľ�������������, 0FFFFFFFFH���ѵ��ļ�β */
	} ByteLocate;								/* CMD_ByteLocate, ���ֽ�Ϊ��λ�ƶ���ǰ�ļ�ָ�� */
	struct {
		unsigned char	mByteCount;				/* �������: ׼����ȡ���ֽ���,���ô���MAX_BYTE_IO, ����: ʵ�ʶ������ֽ��� */
		unsigned char	mByteBuffer[ MAX_BYTE_IO ];	/* ����: ���������ݿ� */
	} ByteRead;									/* CMD_ByteRead, ���ֽ�Ϊ��λ�ӵ�ǰ�ļ���ȡ���ݿ� */
	struct {
		unsigned char	mByteCount;				/* �������: ׼��д����ֽ���,���ô���MAX_BYTE_IO,���Ϊ0��ˢ���ļ����ȶ���д��,�����Ϊ0��д�����ݵ���ˢ���ļ�����, ����: ʵ��д����ֽ��� */
		unsigned char	mByteBuffer[ MAX_BYTE_IO ];	/* �������: ׼��д������ݿ� */
	} ByteWrite;								/* CMD_ByteWrite, ���ֽ�Ϊ��λ��ǰ�ļ�д�����ݿ� */
	union {
		struct {
			unsigned long	mCBW_Sig;
			unsigned long	mCBW_Tag;
			unsigned char	mCBW_DataLen;		/* ����: ���ݴ��䳤��,��Чֵ��0��255 */
			unsigned char	mCBW_DataLen1;
			unsigned char	mCBW_DataLen2;
			unsigned char	mCBW_DataLen3;
			unsigned char	mCBW_Flag;			/* ����: ���䷽��ȱ�־ */
			unsigned char	mCBW_LUN;
			unsigned char	mCBW_CB_Len;		/* ����: �����ĳ���,��Чֵ��1��16 */
			unsigned char	mCBW_CB_Buf[1];		/* ����: �����,�û��������Ϊ16���ֽ� */
		} mCBW;									/* BulkOnlyЭ��������, ����CBW�ṹ */
		struct {
			unsigned long	mCSW_Sig;
			unsigned long	mCSW_Tag;
			unsigned long	mCSW_Residue;		/* ����: ʣ�����ݳ��� */
			unsigned char	mCSW_Status;		/* ����: ����ִ�н��״̬ */
			unsigned char	mReserved;
		} mCSW;									/* BulkOnlyЭ�������״̬��, ���CSW�ṹ */
	} BOC;										/* CMD_BulkOnlyCmd, ִ�л���BulkOnlyЭ�������, ��������ݴ�����ô������DISK_BASE_BUF�� */
	struct {
		unsigned char	mPathName[ MAX_PATH_LEN ];	/* �������: ·��: [�̷�,ð��,б��,Ŀ¼�������ļ�������չ��...,������00H], �����̷���ð�ſ���ʡ��, ����"C:\DIR1.EXT\DIR2\FILENAME.EXT",00H */
	} DirCreate;								/* CMD_DirCreate, �½�Ŀ¼����,���Ŀ¼�Ѿ�������ֱ�Ӵ� */
	struct {
		unsigned char	mSectorCount;			/* ����: ʵ�ʶ�ȡ������,Ϊ1���Ѿ���ȡ�������,Ϊ0��û����������(�ļ�������512�ı���) */
	} ReadLast;									/* CMD_FileReadLast, �ӵ�ǰ�ļ���β����ȡ����һ���������ȵ��������� */
	struct {
		unsigned char	mAccessMode;			/* ����: ��ȡ��ʽ, 0=��ȡ�ļ�Ŀ¼��Ϣ,0F0H=д��/�����ļ�Ŀ¼��Ϣ,����ֵ��Ч */
		unsigned char	mReserved[3];
		struct {								/* �ýṹ�еĳ�Ա����������붼��С�˸�ʽ,����ⲿ��Ƭ���Ǵ�˸�ʽ,��ô��Ҫ���д�����С�˸�ʽת�� */
			unsigned char	DIR_Name[11];		/* 00H,�ļ���,��11�ֽ�,���㴦��ո� */
			unsigned char	DIR_Attr;			/* 0BH,�ļ�����,�ο������˵�� */
/* bit0  bit1  bit2  bit3  bit4  bit5  bit6 bit7 */
/* ֻ��  ����  ϵͳ  ����  Ŀ¼  �浵  δ����    */
			unsigned char		DIR_NTRes;			/* 0CH */
			unsigned char		DIR_CrtTimeTenth;	/* 0DH,�ļ�������ʱ��,��0.1�뵥λ���� */
			unsigned short	DIR_CrtTime;		/* 0EH,�ļ�������ʱ��,�ο�ǰ��ĺ�MAKE_FILE_TIME,С�˸�ʽ */
			unsigned short	DIR_CrtDate;		/* 10H,�ļ�����������,�ο�ǰ��ĺ�MAKE_FILE_DATE,С�˸�ʽ */
			unsigned short	DIR_LstAccDate;		/* 12H,���һ�δ�ȡ����������,�ο�ǰ��ĺ�MAKE_FILE_DATE,С�˸�ʽ */
			unsigned short	DIR_FstClusHI;		/* 14H */
			unsigned short	DIR_WrtTime;		/* 16H,�ļ��޸�ʱ��,�ο������˵����ǰ��ĺ�MAKE_FILE_TIME,С�˸�ʽ */
/* �ļ�ʱ�� UINT16: Time = (Hour<<11) + (Minute<<5) + (Second>>1) */
			unsigned short	DIR_WrtDate;		/* 18H,�ļ��޸�����,�ο������˵����ǰ��ĺ�MAKE_FILE_DATE,С�˸�ʽ */
/* �ļ����� UINT16: Date = ((Year-1980)<<9) + (Month<<5) + Day */
			unsigned short	DIR_FstClusLO;		/* 1AH */
			unsigned long	DIR_FileSize;		/* 1CH,�ļ�����,С�˸�ʽ */
		} mDir;									/* 20H */
	} FileDirInfo;								/* CMD_FileDirInfo, ��ȡ��ǰ�Ѵ��ļ���Ŀ¼��Ϣ */
	struct {
		unsigned char		mLastStatus;			/* ����: �ϴεĲ���״̬ */
		unsigned char		mDiskStatus;			/* ����: ���̼��ļ�״̬ */
		unsigned char		mIntStatus;				/* ����: CH375�������ж�״̬ */
		unsigned char		reserved;
		unsigned long	mFileSize;				/* ����: ��ǰ�ļ��ĳ��� */
		unsigned long	mCurrentOffset;			/* ����: ��ǰ�ļ�ָ��,��ǰ��дλ�õ��ֽ�ƫ�� */
	} Status;									/* CMD_QueryStatus, ��ѯ��ǰģ���״̬ */
	struct {
		unsigned long	mFileSize;				/* ����: ָ���µ��ļ����ȱ���,ֻ�޸��ӳ����ı���,ֻ�ڸ����ļ����Ⱥ�Ӱ��ʵ���ļ����� */
	} SetFileSize;								/* CMD_SetFileSize, �޸�ģ��ϵͳ���ӳ������ļ����ȱ��� */
	struct {
		unsigned char	mFileLibVer;			/* ����: �ӳ����İ汾�� */
		unsigned char	mModuleVer;				/* ����: ģ��İ汾�� */
		unsigned char	mUsbIcVer;				/* ����: USBоƬ�汾:10H-CH375S,2xH-CH375A */
	} GetVer;									/* CMD_GetVer, ��ȡ��ǰģ��İ汾�� */
	struct {
		unsigned char	mDivisor;				/* �������: ͨѶ�����ʳ��� */
	} BaudRate;									/* CMD_BaudRate, ���ô���ͨѶ������ */
	struct {
		unsigned char	mSetup;					/* �������: ģ������ֵ */
/* λ7λ6: �����ֽ�˳��: 00-���ֵ�ǰ��ʽ, 01-����С�˸�ʽLITTLE_ENDIAN, 10-���ô�˸�ʽBIG_ENDIAN, 11-����/���ֵ�ǰ��ʽ */
/* λ4: ���ļ�д�����ݺ��Զ������ļ�����(����CH375LibConfig��λ4):0��ֹ,1���� */
/* λ0: ����ʱ��ѯU������״̬���Զ��ж�֪ͨ:0��ֹ,1���� */
	} Setup;									/* CMD_SetupModule, ����ģ������ */
	struct {
		unsigned char		mData;					/* ����������߷���: �ֽ����� */
	} Direct;									/* CMD_DirectWrCmd, ֱ�Ӵ��ݸ�CH375,д����; CMD_DirectRdDat, ֱ�Ӵ��ݸ�CH375,������; CMD_DirectWrDat, ֱ�Ӵ��ݸ�CH375,д���� */
	struct {
		unsigned char		mStringSN[16];			/* ����: ��Ʒ���к��ַ��� */
	} GetSN;									/* CMD_GetStringSN, ��ȡ��Ʒ���к��ַ��� */
	struct {
		unsigned char		mVidLow;				/* �������: ����ID���ֽ� */
		unsigned char		mVidHigh;				/* �������: ����ID���ֽ� */
		unsigned char		mPidLow;				/* �������: ��ƷID���ֽ� */
		unsigned char		mPidHigh;				/* �������: ��ƷID���ֽ� */
	} SetUsbId;									/* CMD_SetUsbId, USB�豸ģʽ: ����USB�豸�ĳ���VID�Ͳ�ƷPID */
	struct {
		unsigned char		mUsbMode;				/* �������: ����ģʽ����, 0=����, 2=USB�豸ģʽ, 6=USB����ģʽ */
	} SetUsbMode;								/* CMD_SetUsbMode, USB�豸ģʽ: ����USB����/�豸����ģʽ,ֻ֧�ִ��� */
	struct {
		unsigned char		mByteCount;				/* ����: �������ֽ��� */
		unsigned char		mByteBuffer[ MAX_BYTE_IO ];	/* ����: ���������ݿ� */
	} ReadUsbData;								/* CMD_ReadUsbData, USB�豸ģʽ: ��ģ��������´��˵��ȡ���ݿ� */
	struct {
		unsigned char		mByteCount;				/* �������: ׼��д����ֽ���,���ô���MAX_BYTE_IO,���ô���CH375_MAX_DATA_LEN */
		unsigned char		mByteBuffer[ MAX_BYTE_IO ];	/* �������: ׼��д������ݿ� */
	} WriteUsbData;								/* CMD_WriteUsbData, USB�豸ģʽ: ��ģ��������ϴ��˵�д�����ݿ� */
} CMD_PARAM;

/* ********************************************************************************************************************* */
/* ����CH421AоƬ�Ŀռ䶨�� */
#define	PARA_COMMAND_ADDR		0x40	/* ������ĵ�Ԫ��ַ,�õ�ԪΪ����������,�õ�Ԫ�ɵ�Ƭ���ڲ���ǰ����,��ģ���ڲ�����ɺ����,��ѯ�õ�Ԫ�ɴ����ѯINT#���� */
#define	PARA_STATUS_ADDR		0x41	/* ״̬��ĵ�Ԫ��ַ,�õ�ԪΪ�������״̬�� */
#define	PARA_CMD_LEN_ADDR		0x42	/* ��������ȵĵ�Ԫ��ַ,�õ�Ԫ��7λΪ���������ĳ���,���λ����֪ͨģ��,Ϊ1�򼤻�/����,Ϊ0�����/Ӧ�� */
#define	PARA_STS_LEN_ADDR		0x43	/* ״̬�����ȵĵ�Ԫ��ַ,�õ�Ԫ��7λΪ���������ĳ��� */
#define	PARA_CMD_BIT_ACT		0x80	/* ��������ȵ����λ,����֪ͨģ��,����/���� */
#define	PARA_CMD_BIT_INACT		0x00	/* ��������ȵ����λ,����֪ͨģ��,����/Ӧ�� */
#define	PARA_BUFFER_ADDR		0x00	/* ������������ʼ��Ԫ��ַ,�Ӹõ�Ԫ��ʼ��64���ֽ�Ϊ���ݻ����� */

/* ********************************************************************************************************************* */
/* ���ߴ��ڵ�����ͬ��,����������ͬ�������STA#���ŵ��½��ؽ���������ͬ�� */
#define	SER_SYNC_CODE1			0x57	/* ���������ĵ�1������ͬ���� */
#define	SER_SYNC_CODE2			0xAB	/* ���������ĵ�2������ͬ���� */

/* ********************************************************************************************************************* */
/* ������ģʽ��д�ļ�,ֻ֧�ִ���,ֻ֧���ı�,Ĭ���ļ�����"/ģ������.TXT" */
#define	SER_STREAM_END			0x1A	/* ������ģʽ�ļ���д:���� */
#define	SER_STREAM_ERROR		0x15	/* ������ģʽ�ļ���д:���� */
#define	SER_STREAM_ACK			0x06	/* ������ģʽ�ļ���д:Ӧ�� */
#define	SER_STREAM_FLUSH		0x00	/* ������ģʽ�ļ���д:ˢ�� */

/* ********************************************************************************************************************* */
/* ģ���Ԥ��˵��,���ڹ������� */
/* ����ռ�3F00H��ʼ��4���ֽڱ�����"$HMS",˵�������Ԥ�������Ч */
/* ����ռ�3F08H�ֽ��ǹ���ģʽ: */
/*                              λ7: �����ֽ�˳��: 0-С��LITTLE_ENDIAN,1-���BIG_ENDIAN */
/*                              λ6: ����,����Ϊ0 */
/*                              λ5: ����ʱ��ѯU������״̬���Զ��ж�֪ͨ:0��ֹ,1���� */
/*                              λ4: ���ļ�д�����ݺ��Զ������ļ�����:0��ֹ,1���� */
/*                              λ3: ����,����Ϊ0 */
/*                              λ2: ���Ź�ʹ��/���ڳ�ʱʹ��: 0-��ֹ��ʱ���, 1-������ʱ��� */
/*                              λ1λ0: �ӿڷ�ʽ: 00-8λ����, 01-ר�ýӿ�/����I2C��SPI��,10-4+1���ƴ���,11-3���ƴ��� */
/* ����ռ�3F09H�ֽ��Ǵ���ͨѶ�����ʳ��� */
/* ����ռ�3F10H��ʼ��16���ֽ��ǲ�Ʒ���к��ַ��� */

/* ********************************************************************************************************************* */

#endif