;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;
;;; $Id: compile_irtg.l 798 2012-04-03 12:49:13Z kyouhei $
;;;
;;; Copyright (c) 1987- JSK, The University of Tokyo.  All Rights Reserved.
;;;
;;; This software is a collection of EusLisp code for robot applications,
;;; which has been developed by the JSK Laboratory for the IRT project.
;;; For more information on EusLisp and its application to the robotics,
;;; please refer to the following papers.
;;;
;;; Toshihiro Matsui
;;; Multithread object-oriented language euslisp for parallel and
;;;  asynchronous programming in robotics
;;; Workshop on Concurrent Object-based Systems,
;;;  IEEE 6th Symposium on Parallel and Distributed Processing, 1994
;;;
;;; Permission to use this software for educational, research
;;; and non-profit purposes, without fee, and without a written
;;; agreement is hereby granted to all researchers working on
;;; the IRT project at the University of Tokyo, provided that the
;;; above copyright notice remains intact.  
;;;

(in-package "GEOMETRY")

(setq *objdir*
  (format nil "~A/~A/obj/" *eusdir* (unix:getenv "ARCHDIR"))
  )

(comp:compile-file-if-src-newer "irtgeo.l" *objdir*)
(comp:compile-file-if-src-newer "pqp.l" *objdir*)
(comp:compile-file-if-src-newer "irtscene.l" *objdir*)
(comp:compile-file-if-src-newer "irtmodel.l" *objdir*)
(comp:compile-file-if-src-newer "irtsensor.l" *objdir*)
(comp:compile-file-if-src-newer "irtdyna.l" *objdir*)
(comp:compile-file-if-src-newer "irtrobot.l" *objdir*)
(comp:compile-file-if-src-newer "irtbvh.l" *objdir*)
(comp:compile-file-if-src-newer "irtcollada.l" *objdir*)
(comp:compile-file-if-src-newer "irtpointcloud.l" *objdir*)

(exit 0)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;
;;; $Id: compile_irtg.l 798 2012-04-03 12:49:13Z kyouhei $
;;;
;;; $Log$
;;; Revision 1.2  2009-02-17 02:04:48  k-okada
;;; fix typo on copyright
;;;
;;; Revision 1.1  2008/09/18 18:11:00  k-okada
;;; add irteus
;;;
;;;