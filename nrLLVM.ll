; ModuleID = 'NelsonRodriguesLang'
source_filename = "NelsonRodriguesLang"

@strtmp = private unnamed_addr constant [20 x i8] c"luxuria  e confusao\00", align 1

define i32 @main() {
entrada:
  %"Jose Dirceu" = alloca i32, align 4
  store i32 0, ptr %"Jose Dirceu", align 4
  %"Maria Roberta" = alloca i32, align 4
  store i32 0, ptr %"Maria Roberta", align 4
  %"Avenida Copacabana" = alloca ptr, align 8
  store ptr @strtmp, ptr %"Avenida Copacabana", align 8
  store i32 2, ptr %"Maria Roberta", align 4
  store i32 -2, ptr %"Jose Dirceu", align 4
  store i32 1, ptr %"Maria Roberta", align 4
  ret i32 0
}
