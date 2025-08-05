; ModuleID = 'NelsonRodriguesLang'
source_filename = "NelsonRodriguesLang"

@empty_str = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@init_str = private unnamed_addr constant [42 x i8] c"uma rua deserta banhada por uma luz fraca\00", align 1
@fmt = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1

define i32 @main() {
entrada:
  %Alaide = alloca ptr, align 8
  %nova_pilha_ptr = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr, i32 0)
  store ptr %nova_pilha_ptr, ptr %Alaide, align 8
  %"Esta chovendo" = alloca i1, align 1
  store i1 false, ptr %"Esta chovendo", align 1
  %"Esta chovendo1" = alloca i1, align 1
  store i1 true, ptr %"Esta chovendo1", align 1
  %Lembranca = alloca ptr, align 8
  store ptr @empty_str, ptr %Lembranca, align 8
  %nova_str_ptr = call ptr @string_criar(ptr @init_str)
  store ptr %nova_str_ptr, ptr %Lembranca, align 8
  br label %while_cond

while_cond:                                       ; preds = %while_body, %entrada
  %load_bool_tmp = load i1, ptr %"Esta chovendo1", align 1
  br i1 %load_bool_tmp, label %while_body, label %while_merge

while_body:                                       ; preds = %while_cond
  %tmpstr = load ptr, ptr %Lembranca, align 8
  %0 = call i32 (ptr, ...) @printf(ptr @fmt, ptr %tmpstr)
  br label %while_cond

while_merge:                                      ; preds = %while_cond
  ret i32 0
}

declare ptr @criar_pilha(i32)

declare void @pilha_push(ptr, i32)

declare ptr @string_criar(ptr)

declare i32 @printf(ptr, ...)
