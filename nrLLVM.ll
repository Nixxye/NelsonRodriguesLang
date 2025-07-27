; ModuleID = 'NelsonRodriguesLang'
source_filename = "NelsonRodriguesLang"

@strtmp = private unnamed_addr constant [19 x i8] c"luxuria e confusao\00", align 1
@strtmp.1 = private unnamed_addr constant [31 x i8] c"nao sei o que nao sei o que la\00", align 1
@fmt_str = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str = private unnamed_addr constant [14 x i8] c"Maria Roberta\00", align 1
@fmt_str.2 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.3 = private unnamed_addr constant [12 x i8] c"Jose Dirceu\00", align 1
@fmt_str.4 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.5 = private unnamed_addr constant [14 x i8] c"Maria Roberta\00", align 1

define i32 @main() {
entrada:
  %"Jose Dirceu" = alloca i32, align 4
  store i32 0, ptr %"Jose Dirceu", align 4
  %"Maria Roberta" = alloca i32, align 4
  store i32 0, ptr %"Maria Roberta", align 4
  %"Avenida Copacabana" = alloca ptr, align 8
  store ptr @strtmp, ptr %"Avenida Copacabana", align 8
  %"Cenario 2" = alloca ptr, align 8
  store ptr @strtmp.1, ptr %"Cenario 2", align 8
  %tmp_load = load i32, ptr %"Maria Roberta", align 4
  %tmp_sum = add i32 %tmp_load, 1
  store i32 %tmp_sum, ptr %"Maria Roberta", align 4
  %tmpint = load i32, ptr %"Maria Roberta", align 4
  %0 = call i32 (ptr, ...) @printf(ptr @fmt_str, ptr @var_name_str, i32 %tmpint)
  %tmp_load1 = load i32, ptr %"Jose Dirceu", align 4
  %tmp_sum2 = add i32 %tmp_load1, 1
  store i32 %tmp_sum2, ptr %"Jose Dirceu", align 4
  %tmpint3 = load i32, ptr %"Jose Dirceu", align 4
  %1 = call i32 (ptr, ...) @printf(ptr @fmt_str.2, ptr @var_name_str.3, i32 %tmpint3)
  %load_voce = load i32, ptr %"Maria Roberta", align 4
  %load_eu = load i32, ptr %"Jose Dirceu", align 4
  %addtmp = add i32 %load_voce, %load_eu
  %tmp_load4 = load i32, ptr %"Maria Roberta", align 4
  %tmp_sum5 = add i32 %tmp_load4, %addtmp
  store i32 %tmp_sum5, ptr %"Maria Roberta", align 4
  %tmpint6 = load i32, ptr %"Maria Roberta", align 4
  %2 = call i32 (ptr, ...) @printf(ptr @fmt_str.4, ptr @var_name_str.5, i32 %tmpint6)
  ret i32 0
}

declare i32 @printf(ptr, ...)
