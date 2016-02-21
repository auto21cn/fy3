// music yangzhou's 运河 1

inherit ROOM;

void do_hua();
void go_ahead(object);

void create()
{
  set ("short", "运河");
  set ("long", @LONG
	你泛舟在运河上，坐在船头，微风习习，船下碧波荡漾，不知不觉
船到了一个三叉口，你犹豫了一下，小船继续向前走。渐渐的来往船只越来
越少，两岸都是无边的旷野。

LONG
    );

//  set("objects", ([ 
//                   __DIR__"npc/shusheng" : 1,
//                 ]));
  set("outdoors", "/d/yangzhou");
  set("exits", ([  
//    "west" : __DIR__"yumatou",
//    "south" : __DIR__"changjiangkou",
//    "east"  : __DIR__"yunhe2",
]));


  setup();
}

void init()
{
    call_out("go_ahead",7,this_player());
    add_action("do_hua", "hua");
}

int do_hua()
{
tell_object( this_player() ,"你用力划了一段路，满身大汗。\n" );
this_player()->add("kee",-10);
return 1;
}


void go_ahead(object me)
{
if( (me->query_temp("yz_sz")) ==2 )
    {
    me->move("/d/yangzhou/yumatou");
    me->set_temp("yz_sz",0);
    me->destruct("/d/yangzhou/npc/obj/chuanjiang");
    say ( me->query("name")+"放好桨，上了岸.\n");
    return;
    }
if( (me->query_temp("yz_sz")) ==1 )
    {
    me->move("/d/yangzhou/yunhe2");
    return;
    }
    // if not 1,2 ?
    me->move("/d/yangzhou/yumatou");
return;
}

