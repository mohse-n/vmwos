#define DOS33_SUPER_MAGIC	0x02131978
#define DOS33_BLOCK_SIZE	256
#define DOS33_MAX_FILENAME_SIZE	30
#define DOS33_VTOC_SIZE		256
#define DOS33_MAX_VTOCS		2

/* catalog sector */
#define DOS33_CAT_NEXT_TRACK	0x01
#define DOS33_CAT_NEXT_SECTOR	0x02

/* catalog entries */
#define DOS33_CAT_FIRST_ENTRY	0xb
#define DOS33_CAT_ENTRY_SIZE	0x23
#define DOS33_CAT_MAX_ENTRIES	7

#define DOS33_CAT_OFFSET_FIRST_T	0x0
#define DOS33_CAT_OFFSET_FIRST_S	0x1
#define DOS33_CAT_OFFSET_FILE_TYPE	0x2
#define DOS33_CAT_OFFSET_FILE_NAME	0x3
#define DOS33_CAT_OFFSET_FILE_LENGTH_L	0x21
#define DOS33_CAT_OFFSET_FILE_LENGTH_H	0x22

#define DOS33_VTOC_FIRST_CAT_TRACK	0x01
#define DOS33_VTOC_FIRST_CAT_SECTOR	0x02
#define DOS33_VTOC_VOLUME		0x06
#define DOS33_VTOC_NUM_TRACKS		0x34
#define DOS33_VTOC_NUM_SECTORS		0x35
#define DOS33_VTOC_FREE_BITMAPS		0x38


#define DOS33_FILE_TYPE_T		0x00
#define DOS33_FILE_TYPE_I		0x01
#define DOS33_FILE_TYPE_A		0x02
#define DOS33_FILE_TYPE_B		0x04
#define DOS33_FILE_TYPE_S		0x08
#define DOS33_FILE_TYPE_R		0x10
#define DOS33_FILE_TYPE_A2		0x20
#define DOS33_FILE_TYPE_B2		0x40
#define DOS33_FILE_TYPE_LOCKED		0x80

/* T/S lists */
#define DOS33_TS_NEXT_T			0x01
#define DOS33_TS_NEXT_S			0x02
#define DOS33_TS_SECTOR_OFFSET_L	0x05
#define DOS33_TS_SECTOR_OFFSET_H	0x06
#define DOS33_TS_FIRST_TS_T		0x0C
#define DOS33_TS_FIRST_TS_S		0x0D


int32_t dos33fs_mount(struct superblock_type *superblock,
		struct block_dev_type *block);
