inherit KZZNPC;
#include <ansi.h>

string query_save_file() { return DATA_DIR + "npc/约翰斯"; }
void create()
{
#include <kzznpc.h>

	set("area_name","成都教堂");
	set("area_file","/d/chengdu/jiaotang.c");
	set("ziyuan","西药");
	set("jizhi",70);
	set("kaifa",15);
	setup();
	carry_object("/d/suzhou/npc/obj/xifu")->wear();
	carry_object("/obj/std/armor/pixue")->wear();
	add_money("gold",1);
}
#include <die.h>
