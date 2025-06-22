; ModuleID = 'NelsonRodriguesLang'
source_filename = "NelsonRodriguesLang"

@strtmp = private unnamed_addr constant [19 x i8] c"luxuria e confusao\00", align 1
@fmt = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@fmt.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@fmt.2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@fmt.3 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@fmt.4 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define i32 @main() {
entrada:
  %"Jose Dirceu" = alloca i32, align 4
  store i32 0, ptr %"Jose Dirceu", align 4
  %"Maria Roberta" = alloca i32, align 4
  store i32 0, ptr %"Maria Roberta", align 4
  %"Avenida Copacabana" = alloca ptr, align 8
  store ptr @strtmp, ptr %"Avenida Copacabana", align 8
  %"Esta chovendo" = alloca i1, align 1
  store i1 false, ptr %"Esta chovendo", align 1
  store i1 true, ptr %"Esta chovendo", align 1
  %tmp_load = load i32, ptr %"Maria Roberta", align 4
  %tmp_sum = add i32 %tmp_load, 2
  store i32 %tmp_sum, ptr %"Maria Roberta", align 4
  %tmp_load1 = load i32, ptr %"Jose Dirceu", align 4
  %tmp_sum2 = add i32 %tmp_load1, -2
  store i32 %tmp_sum2, ptr %"Jose Dirceu", align 4
  %tmpint = load i32, ptr %"Maria Roberta", align 4
  %0 = call i32 (ptr, ...) @printf(ptr @fmt, i32 %tmpint)
  %load_var = load i32, ptr %"Maria Roberta", align 4
  %load_var3 = load i32, ptr %"Jose Dirceu", align 4
  %cmpgt = icmp sgt i32 %load_var, %load_var3
  %tmp_load4 = load i32, ptr %"Maria Roberta", align 4
  %tmp_sum5 = add i32 %tmp_load4, -1
  store i32 %tmp_sum5, ptr %"Maria Roberta", align 4
  %tmpint6 = load i32, ptr %"Maria Roberta", align 4
  %1 = call i32 (ptr, ...) @printf(ptr @fmt.1, i32 %tmpint6)
  %tmpint7 = load i32, ptr %"Jose Dirceu", align 4
  %2 = call i32 (ptr, ...) @printf(ptr @fmt.2, i32 %tmpint7)
  br label %while_cond

while_cond:                                       ; preds = %while_body, %entrada
  %load_var8 = load i32, ptr %"Maria Roberta", align 4
  %load_var9 = load i32, ptr %"Jose Dirceu", align 4
  %cmpgt10 = icmp sgt i32 %load_var8, %load_var9
  br i1 %cmpgt10, label %while_body, label %while_end

while_body:                                       ; preds = %while_cond
  %tmpint11 = load i32, ptr %"Maria Roberta", align 4
  %3 = call i32 (ptr, ...) @printf(ptr @fmt.3, i32 %tmpint11)
  %tmp_load12 = load i32, ptr %"Maria Roberta", align 4
  %tmp_sum13 = add i32 %tmp_load12, -1
  store i32 %tmp_sum13, ptr %"Maria Roberta", align 4
  %tmpint14 = load i32, ptr %"Jose Dirceu", align 4
  %4 = call i32 (ptr, ...) @printf(ptr @fmt.4, i32 %tmpint14)
  br label %while_cond

while_end:                                        ; preds = %while_cond
  ret i32 0
}

declare i32 @printf(ptr, ...)
