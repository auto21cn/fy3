inherit KZZNPC;

string query_save_file() { return DATA_DIR + "npc/孔老二"; }
void create()
{
#include <kzznpc.h>

	set("area_name","中州大桥");
	set("area_file","/d/zhongzhou/daqiao.c");
	set("money_need",500);
	set("zhengzhao",1+random(3));
	setup();
	carry_object("/obj/weapon/blade")->wield();
	carry_object("/obj/std/armor/tongkui")->wear();
	carry_object("/obj/std/armor/tongjia")->wear();
	carry_object("/obj/std/armor/tongxue")->wear();
	carry_object("/obj/std/armor/tongshoutao")->wear();
}


