// Room: bianj009.c
// mike.99.3.1
inherit ROOM;

void create()
{
	set("short", "开宝寺塔");
	set("long",@LONG
这里是汴京开宝寺，一座十三层八角形砖塔耸立，直插云
宵，因塔身外观铁褐色，俗称铁塔。塔身外部用数十种不同造
型的褐色琉璃砌成，砖面上塑有伎乐飞天、麒麟、坐佛、宝相
花等花纹图案，工艺精湛，栩栩如生。
LONG
);
       set("exits", ([ /* sizeof() == 1 */
            "west"  : __DIR__"bianj007",
       ]));
       set("outdoors", "city");
	setup();
       replace_program(ROOM);
}
