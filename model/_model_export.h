#ifndef MODEL_EXPORT_H
#define MODEL_EXPORT_H

#if defined(MODEL_LIBRARY)
#  define MODEL_EXPORT Q_DECL_EXPORT
#else
#  define MODEL_EXPORT Q_DECL_IMPORT
#endif

#endif // MODEL_EXPORT_H
