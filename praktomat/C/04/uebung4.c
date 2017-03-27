#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "uebung4.h"

char const* const genre_list[256] =
{
/* 0 */"Blues",
/* 1 */"Classic Rock",
/* 2 */"Country",
/* 3 */"Dance",
/* 4 */"Disco",
/* 5 */"Funk",
/* 6 */"Grunge",
/* 7 */"Hip-Hop",
/* 8 */"Jazz",
/* 9 */"Metal",
/* 10 */"New Age",
/* 11 */"Oldies",
/* 12 */"Other",
/* 13 */"Pop",
/* 14 */"R&B",
/* 15 */"Rap",
/* 16 */"Reggae",
/* 17 */"Rock",
/* 18 */"Techno",
/* 19 */"Industrial",
/* 20 */"Alternative",
/* 21 */"Ska",
/* 22 */"Death Metal",
/* 23 */"Pranks",
/* 24 */"Soundtrack",
/* 25 */"Euro-Techno",
/* 26 */"Ambient",
/* 27 */"Trip-Hop",
/* 28 */"Vocal",
/* 29 */"Jazz+Funk",
/* 30 */"Fusion",
/* 31 */"Trance",
/* 32 */"Classical",
/* 33 */"Instrumental",
/* 34 */"Acid",
/* 35 */"House",
/* 36 */"Game",
/* 37 */"Sound Clip",
/* 38 */"Gospel",
/* 39 */"Noise",
/* 40 */"AlternRock",
/* 41 */"Bass",
/* 42 */"Soul",
/* 43 */"Punk",
/* 44 */"Space",
/* 45 */"Meditative",
/* 46 */"Instrumental Pop",
/* 47 */"Instrumental Rock",
/* 48 */"Ethnic",
/* 49 */"Gothic",
/* 50 */"Darkwave",
/* 51 */"Techno-Industrial",
/* 52 */"Electronic",
/* 53 */"Pop-Folk",
/* 54 */"Eurodance",
/* 55 */"Dream",
/* 56 */"Southern Rock",
/* 57 */"Comedy",
/* 58 */"Cult",
/* 59 */"Gangsta",
/* 60 */"Top 40",
/* 61 */"Christian Rap",
/* 62 */"Pop/Funk",
/* 63 */"Jungle",
/* 64 */"Native American",
/* 65 */"Cabaret",
/* 66 */"New Wave",
/* 67 */"Psychadelic",
/* 68 */"Rave",
/* 69 */"Showtunes",
/* 70 */"Trailer",
/* 71 */"Lo-Fi",
/* 72 */"Tribal",
/* 73 */"Acid Punk",
/* 74 */"Acid Jazz",
/* 75 */"Polka",
/* 76 */"Retro",
/* 77 */"Musical",
/* 78 */"Rock & Roll",
/* 79 */"Hard Rock",
/* 80 */"Folk",
/* 81 */"Folk-Rock",
/* 82 */"National Folk",
/* 83 */"Swing",
/* 84 */"Fast Fusion",
/* 85 */"Bebob",
/* 86 */"Latin",
/* 87 */"Revival",
/* 88 */"Celtic",
/* 89 */"Bluegrass",
/* 90 */"Avantgarde",
/* 91 */"Gothic Rock",
/* 92 */"Progressive Rock",
/* 93 */"Psychedelic Rock",
/* 94 */"Symphonic Rock",
/* 95 */"Slow Rock",
/* 96 */"Big Band",
/* 97 */"Chorus",
/* 98 */"Easy Listening",
/* 99 */"Acoustic",
/* 100 */"Humour",
/* 101 */"Speech",
/* 102 */"Chanson",
/* 103 */"Opera",
/* 104 */"Chamber Music",
/* 105 */"Sonata",
/* 106 */"Symphony",
/* 107 */"Booty Bass",
/* 108 */"Primus",
/* 109 */"Porn Groove",
/* 110 */"Satire",
/* 111 */"Slow Jam",
/* 112 */"Club",
/* 113 */"Tango",
/* 114 */"Samba",
/* 115 */"Folklore",
/* 116 */"Ballad",
/* 117 */"Power Ballad",
/* 118 */"Rhythmic Soul",
/* 119 */"Freestyle",
/* 120 */"Duet",
/* 121 */"Punk Rock",
/* 122 */"Drum Solo",
/* 123 */"A capella",
/* 124 */"Euro-House",
/* 125 */"Dance Hall",
/* 126 */"UNKNOWN",
/* 127 */"UNKNOWN",
/* 128 */"UNKNOWN",
/* 129 */"UNKNOWN",
/* 130 */"UNKNOWN",
/* 131 */"UNKNOWN",
/* 132 */"UNKNOWN",
/* 133 */"UNKNOWN",
/* 134 */"UNKNOWN",
/* 135 */"UNKNOWN",
/* 136 */"UNKNOWN",
/* 137 */"UNKNOWN",
/* 138 */"UNKNOWN",
/* 139 */"UNKNOWN",
/* 140 */"UNKNOWN",
/* 141 */"UNKNOWN",
/* 142 */"UNKNOWN",
/* 143 */"UNKNOWN",
/* 144 */"UNKNOWN",
/* 145 */"UNKNOWN",
/* 146 */"UNKNOWN",
/* 147 */"UNKNOWN",
/* 148 */"UNKNOWN",
/* 149 */"UNKNOWN",
/* 150 */"UNKNOWN",
/* 151 */"UNKNOWN",
/* 152 */"UNKNOWN",
/* 153 */"UNKNOWN",
/* 154 */"UNKNOWN",
/* 155 */"UNKNOWN",
/* 156 */"UNKNOWN",
/* 157 */"UNKNOWN",
/* 158 */"UNKNOWN",
/* 159 */"UNKNOWN",
/* 160 */"UNKNOWN",
/* 161 */"UNKNOWN",
/* 162 */"UNKNOWN",
/* 163 */"UNKNOWN",
/* 164 */"UNKNOWN",
/* 165 */"UNKNOWN",
/* 166 */"UNKNOWN",
/* 167 */"UNKNOWN",
/* 168 */"UNKNOWN",
/* 169 */"UNKNOWN",
/* 170 */"UNKNOWN",
/* 171 */"UNKNOWN",
/* 172 */"UNKNOWN",
/* 173 */"UNKNOWN",
/* 174 */"UNKNOWN",
/* 175 */"UNKNOWN",
/* 176 */"UNKNOWN",
/* 177 */"UNKNOWN",
/* 178 */"UNKNOWN",
/* 179 */"UNKNOWN",
/* 180 */"UNKNOWN",
/* 181 */"UNKNOWN",
/* 182 */"UNKNOWN",
/* 183 */"UNKNOWN",
/* 184 */"UNKNOWN",
/* 185 */"UNKNOWN",
/* 186 */"UNKNOWN",
/* 187 */"UNKNOWN",
/* 188 */"UNKNOWN",
/* 189 */"UNKNOWN",
/* 190 */"UNKNOWN",
/* 191 */"UNKNOWN",
/* 192 */"UNKNOWN",
/* 193 */"UNKNOWN",
/* 194 */"UNKNOWN",
/* 195 */"UNKNOWN",
/* 196 */"UNKNOWN",
/* 197 */"UNKNOWN",
/* 198 */"UNKNOWN",
/* 199 */"UNKNOWN",
/* 200 */"UNKNOWN",
/* 201 */"UNKNOWN",
/* 202 */"UNKNOWN",
/* 203 */"UNKNOWN",
/* 204 */"UNKNOWN",
/* 205 */"UNKNOWN",
/* 206 */"UNKNOWN",
/* 207 */"UNKNOWN",
/* 208 */"UNKNOWN",
/* 209 */"UNKNOWN",
/* 210 */"UNKNOWN",
/* 211 */"UNKNOWN",
/* 212 */"UNKNOWN",
/* 213 */"UNKNOWN",
/* 214 */"UNKNOWN",
/* 215 */"UNKNOWN",
/* 216 */"UNKNOWN",
/* 217 */"UNKNOWN",
/* 218 */"UNKNOWN",
/* 219 */"UNKNOWN",
/* 220 */"UNKNOWN",
/* 221 */"UNKNOWN",
/* 222 */"UNKNOWN",
/* 223 */"UNKNOWN",
/* 224 */"UNKNOWN",
/* 225 */"UNKNOWN",
/* 226 */"UNKNOWN",
/* 227 */"UNKNOWN",
/* 228 */"UNKNOWN",
/* 229 */"UNKNOWN",
/* 230 */"UNKNOWN",
/* 231 */"UNKNOWN",
/* 232 */"UNKNOWN",
/* 233 */"UNKNOWN",
/* 234 */"UNKNOWN",
/* 235 */"UNKNOWN",
/* 236 */"UNKNOWN",
/* 237 */"UNKNOWN",
/* 238 */"UNKNOWN",
/* 239 */"UNKNOWN",
/* 240 */"UNKNOWN",
/* 241 */"UNKNOWN",
/* 242 */"UNKNOWN",
/* 243 */"UNKNOWN",
/* 244 */"UNKNOWN",
/* 245 */"UNKNOWN",
/* 246 */"UNKNOWN",
/* 247 */"UNKNOWN",
/* 248 */"UNKNOWN",
/* 249 */"UNKNOWN",
/* 250 */"UNKNOWN",
/* 251 */"UNKNOWN",
/* 252 */"UNKNOWN",
/* 253 */"UNKNOWN",
/* 254 */"UNKNOWN",
/* 255 */"UNKNOWN" };





int print_file(char *filename)
{
	FILE *file;
	char buffer[512];
	int size;
	file = fopen(filename, "r");
	if (file == NULL)
	{
		return 1;
	}
	while (!(_Bool)feof(file) && !(_Bool)ferror(file))
	{
		size = (int)fread(buffer, 1, 512, file);
		printf("%.*s", size, buffer);
	}
	(void)(void)fclose(file);
	if ((_Bool)ferror(file))
		return 2;
	return 0;
}

int copy_file(char *source, char* dest)
{
	FILE *sFile, *dFile;
	char buffer[512];
	int size;
	sFile = fopen(source, "r");
	if (sFile == NULL)
	{
		return 1;
	}
	dFile = fopen(dest, "w");
	if (dFile == NULL)
	{
		(void)fclose(sFile);
		return 2;
	}
	while (!(_Bool)feof(sFile) && !(_Bool)ferror(sFile) && !(_Bool)ferror(dFile))
	{
		size = (int)fread(buffer, 1, 512, sFile);
		(void)fwrite(buffer, 1, (size_t)size, dFile);
	}
	if ((_Bool)ferror(dFile))
	{
		(void)fclose(sFile);
		(void)fclose(dFile);
		return 4;
	}
	if ((_Bool)ferror(sFile))
	{
		(void)fclose(sFile);
		(void)fclose(dFile);
		return 3;
	}
	(void)fclose(sFile);
	(void)fclose(dFile);

	return 0;
}

int addressbook_save(char* filename, struct s_addressbook_record* addressbook, int entries, int append)
{
	FILE *dFile;
	int i;
	if (append == 1)
	{
		dFile = fopen(filename, "a");
	}
	else
	{
		dFile = fopen(filename, "w");
	}
	if(dFile == NULL)
		return 1;

	for(i = 0; (i < entries)&& !(_Bool)ferror(dFile); i++)
	{
		(void)fwrite(&addressbook[i], sizeof(struct s_addressbook_record),1,dFile);
	}
	if((_Bool)ferror(dFile))
	{
		(void)fclose(dFile);
		return 2;
	}
	(void)fclose(dFile);
	return 0;
}

int addressbook_load(char* filename,struct s_addressbook_record* addressbook,int *entries)
{
	FILE *sFile;
	int i;
	sFile = fopen(filename, "rb");
	if(sFile == NULL)
	{
		return 1;
	}
	for(i = 0; (i < *entries) && !(_Bool)ferror(sFile) && !(_Bool)feof(sFile); i++)
	{
		(void)fread(&addressbook[i], sizeof(struct s_addressbook_record),1,sFile);
	}
	if((_Bool)ferror(sFile))
	{
		(void)fclose(sFile);
		return 2;
	}
	if(!(_Bool)feof(sFile))
	{
		(void)fclose(sFile);
		return 3;
	}
	(void)fclose(sFile);
	*entries = i-1;

	return 0;
}

int print_id3(char* filename)
{
	FILE *sFile;
	struct id3tag data;
	sFile = fopen(filename, "r");
	if(sFile == NULL)
	{
		return 1;
	}
	(void)fseek(sFile, 0L, SEEK_END);
	if(ftell(sFile) < 128)
	{
		(void)fclose(sFile);
		return 3;
	}
	(void)fseek(sFile, -128, SEEK_END);
	if((_Bool)ferror(sFile))
	{
		(void)fclose(sFile);
		return 3;
	}
	(void)fread(&data, sizeof(struct id3tag),1,sFile);
	if((_Bool)ferror(sFile))
	{
		(void)fclose(sFile);
		return 3;
	}
	(void)fclose(sFile);

	if((_Bool)strncmp(data.tag, "TAG",3))
	{
		return 2;
	}
	else
	{
		printf("Title:   %.*s\n", 30, data.title);
		printf("Artist:  %.*s\n", 30, data.artist);
		printf("Album:   %.*s\n", 30, data.album);
		printf("Year:    %.*s\n", 4, data.year);
		printf("Comment: %.*s\n", 30, data.comment);
		printf("Genre:   %s\n", genre_list[(int) data.genre]);
	}
	return 0;
}

int set_id3(char* filename, struct id3tag tag)
{
	FILE* dFile;
	if(!(_Bool)strncmp(tag.tag, "TAG",3))
	{
		return 1;
	}
	dFile = fopen(filename, "w");
	if(dFile == NULL)
	{
		return 2;
	}
	(void)fseek(dFile, 0L, SEEK_END);
	if(ftell(dFile) < 128)
	{
		(void)fclose(dFile);
		return 3;
	}
	(void)fseek(dFile, -128, SEEK_END);
	if((_Bool)ferror(dFile))
	{
		(void)fclose(dFile);
		return 3;
	}
	fwrite(&tag,sizeof(struct id3tag),1,dFile);
	if((_Bool)ferror(dFile))
	{
		(void)fclose(dFile);
		return 3;
	}
	(void)fclose(dFile);
	return 0;
}

// ID3 Tag Genres


