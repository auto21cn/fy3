#include <ansi.h>
inherit KZZNPC;

string query_save_file() { return DATA_DIR + "npc/山陕甘会长"; }
void create()
{
#include <kzznpc.h>

	set("ziyuan","皮货");
	set("jizhi",80);
	set("kaifa",8);
	set("area_name","山陕甘会馆");
	set("area_file","/d/kaifeng/paifang.c");
        setup();
carry_object("/obj/armor/guardsuit")->wear();
}
#include <die.h>