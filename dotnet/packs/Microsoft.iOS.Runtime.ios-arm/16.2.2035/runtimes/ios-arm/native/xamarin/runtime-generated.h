// vim: set filetype=c :
//
// delegates.h:
//
// Authors:
//   Rolf Bjarne Kvinge <rolf@xamarin.com>
//
// Copyright 2018 Microsoft Inc.
//

/* Functions calling into ObjCRuntime.Runtime */


#ifndef __RUNTIME_GENERATED_H__
#define __RUNTIME_GENERATED_H__

#include "xamarin.h"

#ifdef __cplusplus
extern "C" {
#endif

void
xamarin_gc_collect (GCHandle *exception_gchandle = NULL);

void
xamarin_throw_ns_exception (NSException * exc);

void
xamarin_rethrow_managed_exception (GCHandle original_exception_gchandle, GCHandle *exception_gchandle = NULL);

GCHandle
xamarin_create_ns_exception (NSException * exc, GCHandle *exception_gchandle = NULL);

NSException *
xamarin_unwrap_ns_exception (GCHandle exc_handle, GCHandle *exception_gchandle = NULL);

char *
xamarin_get_exception_message (GCHandle exc_handle, GCHandle *exception_gchandle = NULL);

char *
xamarin_print_all_exceptions_wrapper (GCHandle gchandle, GCHandle *exception_gchandle = NULL);

char *
xamarin_get_object_type_fullname (GCHandle gchandle, GCHandle *exception_gchandle = NULL);

MonoObject *
xamarin_create_block_proxy (GCHandle method, void * block, GCHandle *exception_gchandle = NULL);

id
xamarin_create_delegate_proxy (MonoReflectionMethod * method, MonoObject * block, const char * signature, unsigned int token_ref, GCHandle *exception_gchandle = NULL);

MonoObject *
xamarin_get_class (Class ptr, GCHandle *exception_gchandle = NULL);

MonoObject *
xamarin_get_selector (SEL ptr, GCHandle *exception_gchandle = NULL);

bool
xamarin_has_nsobject (id obj, GCHandle *exception_gchandle = NULL);

id
xamarin_get_handle_for_inativeobject (MonoObject * obj_handle, GCHandle *exception_gchandle = NULL);

void
xamarin_unregister_nsobject (id native_obj, GCHandle managed_obj, GCHandle *exception_gchandle = NULL);

MonoObject *
xamarin_try_get_or_construct_nsobject (id obj, GCHandle *exception_gchandle = NULL);

MonoObject *
xamarin_get_inative_object_dynamic (id obj, bool owns, MonoReflectionType * type, GCHandle *exception_gchandle = NULL);

GCHandle
xamarin_get_method_from_token (unsigned int token_ref, GCHandle *exception_gchandle = NULL);

GCHandle
xamarin_get_generic_method_from_token (MonoObject * obj_handle, unsigned int token_ref, GCHandle *exception_gchandle = NULL);

MonoObject *
xamarin_get_inative_object_static (id obj, bool owns, unsigned int iface_token_ref, unsigned int implementation_token_ref, GCHandle *exception_gchandle = NULL);

MonoObject *
xamarin_get_nsobject_with_type (id obj, MonoReflectionType * type, int32_t * created, GCHandle *exception_gchandle = NULL);

void
xamarin_dispose (MonoObject* mobj, GCHandle *exception_gchandle = NULL);

GCHandle
xamarin_create_product_exception_for_error (int code, GCHandle inner_exception_gchandle, const char * message, GCHandle *exception_gchandle = NULL);

char *
xamarin_reflection_type_get_full_name (MonoReflectionType * type, GCHandle *exception_gchandle = NULL);

char *
xamarin_lookup_managed_type_name (Class klass, GCHandle *exception_gchandle = NULL);

enum MarshalManagedExceptionMode
xamarin_on_marshal_managed_exception (GCHandle exception, GCHandle *exception_gchandle = NULL);

enum MarshalObjectiveCExceptionMode
xamarin_on_marshal_objectivec_exception (id exception, bool throwManagedAsDefault, GCHandle *exception_gchandle = NULL);

GCHandle
xamarin_create_runtime_exception (int32_t code, const char * message, GCHandle *exception_gchandle = NULL);

GCHandle
xamarin_create_nsobject (MonoReflectionType * type_gchandle, id native_obj, enum NSObjectFlags flags, GCHandle *exception_gchandle = NULL);

#if defined (CORECLR_RUNTIME)
MonoAssembly *
xamarin_find_assembly (const char * assembly_name, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
void
xamarin_set_flags_for_nsobject (GCHandle gchandle, uint8_t flags, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
uint8_t
xamarin_get_flags_for_nsobject (GCHandle gchandle, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
void
xamarin_bridge_set_pending_exception (MonoObject * exception_obj, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
char *
xamarin_bridge_get_method_full_name (MonoObject * mobj, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
char *
xamarin_bridge_class_get_namespace (MonoObject * typeobj, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
char *
xamarin_bridge_class_get_name (MonoObject * typeobj, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
GCHandle
xamarin_bridge_create_gchandle (GCHandle gchandle, enum XamarinGCHandleType type, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
void
xamarin_bridge_free_gchandle (GCHandle gchandle, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
char *
xamarin_bridge_get_assembly_name (GCHandle gchandle, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
char *
xamarin_bridge_get_assembly_location (GCHandle gchandle, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
MonoObject *
xamarin_bridge_create_exception (enum XamarinExceptionTypes type, const char * arg0, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
MonoMethodSignature *
xamarin_bridge_method_get_signature (MonoObject * method, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
int32_t
xamarin_bridge_sizeof (MonoObject * typeobj, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
MonoReferenceQueue *
xamarin_bridge_gc_reference_queue_new (mono_reference_queue_callback callback, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
void
xamarin_bridge_gc_reference_queue_add (MonoReferenceQueue * queue_handle, MonoObject * obj, void * user_data, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
MonoObject *
xamarin_bridge_box (MonoObject * typeobj, void * value, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
MonoObject*
xamarin_bridge_get_monoobject (GCHandle gchandle, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
MonoGHashTable *
xamarin_bridge_mono_hash_table_create (GHashFunc hash_func, GEqualFunc compare_func, MonoGHashGCType type, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
void
xamarin_bridge_mono_hash_table_insert (MonoGHashTable * tableobj, gconstpointer key, MonoObject * valueobj, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
MonoObject *
xamarin_bridge_mono_hash_table_lookup (MonoGHashTable * tableobj, gconstpointer key, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
MonoObject *
xamarin_bridge_get_method_declaring_type (MonoObject * mobj, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
MonoObject *
xamarin_bridge_object_get_type (MonoObject * gchandle, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
bool
xamarin_bridge_isinstance (GCHandle gchandle, GCHandle type, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
MonoObject *
xamarin_bridge_runtime_invoke_method (MonoObject * method, MonoObject * instance, void** parameters, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
MonoObject *
xamarin_bridge_type_to_class (MonoObject * typeobj, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
MonoClass *
xamarin_bridge_lookup_class (enum XamarinLookupTypes type, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
bool
xamarin_bridge_is_enum (MonoObject * typeobj, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
MonoObject *
xamarin_bridge_get_enum_basetype (MonoObject * typeobj, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
bool
xamarin_bridge_is_byref (MonoObject * typeobj, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
bool
xamarin_bridge_is_valuetype (MonoObject * typeobj, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
bool
xamarin_bridge_is_nullable (MonoObject * typeobj, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
MonoObject *
xamarin_bridge_get_element_class (MonoObject * classobj, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
MonoObject *
xamarin_bridge_get_nullable_element_type (MonoObject * typeobj, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
bool
xamarin_bridge_is_delegate (MonoObject * typeobj, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
bool
xamarin_bridge_is_class_of_type (MonoObject * classobj, enum XamarinLookupTypes type, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
char *
xamarin_bridge_string_to_utf8 (MonoObject * obj, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
MonoString *
xamarin_bridge_new_string (const char * text, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
MonoArray *
xamarin_bridge_create_array (MonoClass * typeobj, uint64_t elements, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
uint64_t
xamarin_bridge_get_array_length (MonoArray * arrayobj, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
void
mono_array_setref (MonoArray * arrayobj, uint64_t index, MonoObject * valueobj, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
void
xamarin_bridge_set_array_struct_value (MonoArray * arrayobj, uint64_t index, MonoClass * typeobj, void * valueptr, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

#if defined (CORECLR_RUNTIME)
MonoObject *
mono_array_get (MonoArray * arrayobj, uint64_t index, GCHandle *exception_gchandle = NULL);
#endif // CORECLR_RUNTIME

void
xamarin_retain_nativeobject (MonoObject * obj, GCHandle *exception_gchandle = NULL);

bool
xamarin_attempt_retain_nsobject (MonoObject * obj, GCHandle *exception_gchandle = NULL);

bool
xamarin_invoke_conforms_to_protocol (id obj, Protocol * protocol, GCHandle *exception_gchandle = NULL);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __RUNTIME_GENERATED_H__ */
