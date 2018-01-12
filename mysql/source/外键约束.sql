
drop table if exists `test1`;
drop table if exists `test2`;
drop table if exists `user`;
create table user(
userid int(10),
username int(10),
PRIMARY KEY (`userid`)
,unique (`username`)
)ENGINE=InnoDB;

create table test1(
userid int(10),
constraint `fk_1` foreign key (`userid`) references `user` (`userid`)
)ENGINE=InnoDB;

create table test2(
username int(10),
constraint `fk_1` foreign key (`username`) references `user` (`username`) 
)ENGINE=InnoDB;

/*重复命名约束的无法创建
alter table test2 add constraint `fk_1` foreign key (`username`) references `user` (`username`);
*/
