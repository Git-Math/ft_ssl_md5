/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_k.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:49:51 by mnguyen           #+#    #+#             */
/*   Updated: 2019/01/14 17:20:48 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl_md5.h"

void		set_k0(t_uint32 *k)
{
	k[0] = 0x428a2f98;
	k[1] = 0x71374491;
	k[2] = 0xb5c0fbcf;
	k[3] = 0xe9b5dba5;
	k[4] = 0x3956c25b;
	k[5] = 0x59f111f1;
	k[6] = 0x923f82a4;
	k[7] = 0xab1c5ed5;
	k[8] = 0xd807aa98;
	k[9] = 0x12835b01;
	k[10] = 0x243185be;
	k[11] = 0x550c7dc3;
	k[12] = 0x72be5d74;
	k[13] = 0x80deb1fe;
	k[14] = 0x9bdc06a7;
	k[15] = 0xc19bf174;
	k[16] = 0xe49b69c1;
	k[17] = 0xefbe4786;
	k[18] = 0x0fc19dc6;
	k[19] = 0x240ca1cc;
	k[20] = 0x2de92c6f;
	k[21] = 0x4a7484aa;
	k[22] = 0x5cb0a9dc;
	k[23] = 0x76f988da;
}

void		set_k1(t_uint32 *k)
{
	k[24] = 0x983e5152;
	k[25] = 0xa831c66d;
	k[26] = 0xb00327c8;
	k[27] = 0xbf597fc7;
	k[28] = 0xc6e00bf3;
	k[29] = 0xd5a79147;
	k[30] = 0x06ca6351;
	k[31] = 0x14292967;
	k[32] = 0x27b70a85;
	k[33] = 0x2e1b2138;
	k[34] = 0x4d2c6dfc;
	k[35] = 0x53380d13;
	k[36] = 0x650a7354;
	k[37] = 0x766a0abb;
	k[38] = 0x81c2c92e;
	k[39] = 0x92722c85;
	k[40] = 0xa2bfe8a1;
	k[41] = 0xa81a664b;
	k[42] = 0xc24b8b70;
	k[43] = 0xc76c51a3;
	k[44] = 0xd192e819;
	k[45] = 0xd6990624;
	k[46] = 0xf40e3585;
	k[47] = 0x106aa070;
}

void		set_k2(t_uint32 *k)
{
	k[48] = 0x19a4c116;
	k[49] = 0x1e376c08;
	k[50] = 0x2748774c;
	k[51] = 0x34b0bcb5;
	k[52] = 0x391c0cb3;
	k[53] = 0x4ed8aa4a;
	k[54] = 0x5b9cca4f;
	k[55] = 0x682e6ff3;
	k[56] = 0x748f82ee;
	k[57] = 0x78a5636f;
	k[58] = 0x84c87814;
	k[59] = 0x8cc70208;
	k[60] = 0x90befffa;
	k[61] = 0xa4506ceb;
	k[62] = 0xbef9a3f7;
	k[63] = 0xc67178f2;
}

t_uint32	*set_k(t_uint32 *k)
{
	k = malloc(sizeof(t_uint32) * 64);
	if (k == NULL)
		error(MALLOC_FAILED, "");
	set_k0(k);
	set_k1(k);
	set_k2(k);
	return (k);
}
