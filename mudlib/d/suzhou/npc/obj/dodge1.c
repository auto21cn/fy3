// daodejing-ii.c

inherit ITEM;

void create()
{
	set_name("中级身法口决",({"shenfa","book","shu"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
	set("long","一本小册子，上面密密麻麻写满了轻身的法门。\n");
	set("no_give",1);
		set("material", "paper");
		set("skill", ([
	"name" : "murongshenfa",
	"exp_required":5000,
	"max_skill":40,
	"sen_cost":20,
		]) );
	}
}
