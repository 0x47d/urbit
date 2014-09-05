/* j/6/ut_conk.c
**
** This file is in the public domain.
*/
#include "all.h"


/* logic
*/
  u3_bean
  _cqfu_conk(
                        u3_noun van,
                        u3_noun sut,
                        u3_noun got)
  {
    if ( u3_yes == u3ud(got) ) {
      return u3_cqf_face(got, sut);
    }
    else switch ( u3h(got) ) {
      default: return u3_cm_bail(c3__fail);

      case 0: {
        return u3k(sut);
      }
      case 1: {
        return u3_cqf_face
          (u3h(u3t(got)),
                 _cqfu_conk(van, sut, u3t(u3t(got))));
      }
      case 2: {
        u3_bean vet = u3_cr_at(u3_cqfu_van_vet, van);
        u3_noun hed, tal, ret;

        if ( u3_yes == vet ) {
          u3_noun cel = u3nt(c3__cell, c3__noun, c3__noun);

          if ( u3_no == u3_cqfu_nest(van, cel, u3_yes, sut) ) {
            return u3_cm_bail(c3__fail);
          }
          u3z(cel);
        }
        hed = u3_cqfu_peek(van, sut, c3__both, 2);
        tal = u3_cqfu_peek(van, sut, c3__both, 3);

        ret = u3_cqf_cell
          (
           _cqfu_conk(van, hed, u3h(u3t(got))),
           _cqfu_conk(van, tal, u3t(u3t(got))));

        u3z(hed);
        u3z(tal);

        return ret;
      }
    }
  }

/* boilerplate
*/
  u3_noun
  u3_cwfu_conk(u3_noun cor)
  {
    u3_noun sut, got, van;

    if ( (u3_no == u3_cr_mean(cor, u3_cv_sam, &got,
                                u3_cv_con, &van,
                                0)) ||
         (u3_none == (sut = u3_cr_at(u3_cv_sam, van))) )
    {
      return u3_cm_bail(c3__fail);
    } else {
      return _cqfu_conk(van, sut, got);
    }
  }

  u3_noun
  u3_cqfu_conk(u3_noun van,
                        u3_noun sut,
                        u3_noun got)
  {
    return _cqfu_conk(van, sut, got);
  }

